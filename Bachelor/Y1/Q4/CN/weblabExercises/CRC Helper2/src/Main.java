public class Main {

    /**
     * If the bit is not a power of 2 you can put the one of the data bits there (starting from left to right).
     * Note: Start from array index = 1 (ignoring arr[0]).
     *
     * @param inputMessage the data bits (also starts at index=1, for consistency)
     * @param totalBits amount of data bits + check bits
     * @return message with data bits placed in the correct positions,
     *          true = bit should be on (1),
     *          false = bit should be off (0)
     */
    static boolean[] placeDataBits(boolean[] inputMessage, int totalBits) {
        boolean[] result = new boolean[totalBits+1];
        result[0] = false;
        int currentIndex = 1;

        for(int i = 1; i <= totalBits; i++){
            if(! isBitPowerOfTwo(i))
                result[i] = inputMessage[currentIndex++];
            else
                result[i] = false;
        }

        return result;
    }

    /**
     * Calculate the check bits based on the placed data bits.
     *
     * Example:
     * ind data  ->   3 567
     * data      -> 0010101
     * ind check -> 12 4
     * check     -> 1000000
     * combined  -> 1010101
     *
     * @param placedDataBits array of booleans (`false` always at index 0, start caring about data from index 1)
     * @param totalBits amount of data bits + check bits
     * @param isEvenParity true if it is even, false otherwise
     * @return the placed check bits
     */
    static boolean[] calculateCheckBits(boolean[] placedDataBits, int totalBits, boolean isEvenParity) {
        int resultSize = placedDataBits.length;

        boolean[] result = new boolean[resultSize];
        for(int i = 1; i < resultSize; i ++){
            result[i] = placedDataBits[i];
        }

        for(int crtBit = 1; crtBit < resultSize; crtBit++){
            if( isBitPowerOfTwo(crtBit)){
                int lBitInd = crtBit,
                        rBitInd = crtBit + crtBit - 1;
                long sum = 0;
                while(lBitInd <= resultSize){
                    sum +=  sumBitsBetweenIndices(placedDataBits, lBitInd, Math.min(rBitInd, resultSize-1));
                    lBitInd += 2*crtBit;
                    rBitInd = lBitInd + crtBit - 1;
                }
                result[crtBit] =  calculateCheckBitToPlace(sum, isEvenParity);
            }
        }

        //result[0] =  calculateCheckBitToPlace(
        // sumBitsBetweenIndices(inputMessage, 1, resultSize-1), isEvenParity);

        return result;
    }

    /**
     * Calculates the hamming code of the given bit sequence.
     *
     * @param inputMessage  The input bit sequence
     * @param isEvenParity = true for even parity, false for odd parity
     * @return The Hamming-encoded sequence
     */
    static long calculateHammingCode(long inputMessage, boolean isEvenParity) {
        boolean[] zaBoolInput =  convertLongToArrayOfBooleans(inputMessage);

        int totalBits =  calculateTotalBits(zaBoolInput) + 1;
        return  convertArrayOfBooleansToLong(
                calculateCheckBits(
                        placeDataBits(
                                zaBoolInput, totalBits)
                        , totalBits, isEvenParity)
        );
    }

    public static void main(String[] args) {

    }
    /**<------------- HELPER METHODS ------------->**/

    /**
     * Check if the bit at index is 1.
     * @param inputMessage a bit string
     * @param index which bit to check
     * @return True if the bit at the respective index is 1,
     *         False otherwise.
     */
    static boolean isBitOnAtIndex(long inputMessage, int index) {
        return ((1L << index) & inputMessage) != 0;
    }

    /**
     * Convert the binary number into an array of booleans,
     *      where true means that the bit at that index is on (1) and false means it is off (0).
     * Positions of the bits in the array should start from left to right,
     *      with the most significant (1) bit being placed at index 1.
     * First value in the array (index = 0) should always be false.
     *
     * @param inputMessage binary number
     * @return the input message converted into an array of booleans
     */
    static boolean[] convertLongToArrayOfBooleans(long inputMessage) {
        int arraySize = calculateMSB(inputMessage) + 1;
        boolean[] result = new boolean[arraySize];

        while(inputMessage > 0){
            int pos = arraySize - calculateMSB(inputMessage);
            result[pos] = true;
            inputMessage = inputMessage ^ (1L << (calculateMSB(inputMessage)-1));
        }

        return result;
    }

    static int calculateMSB(long input){
        return Long.SIZE - Long.numberOfLeadingZeros(input);
    }

    /**
     * Reverse steps from convertLongToArrayOfBooleans.
     * First value in the input array (index = 0) is always false, you should ignore this value.
     * @param inputMessage array of booleans
     * @return the input message converted into a number
     */
    static long convertArrayOfBooleansToLong(boolean[] inputMessage) {
        long result = 0;
        for(int i = 1; i < inputMessage.length; i++){
            result <<= 1L;
            result = result | (inputMessage[i]?1:0);
        }
        return result;
    }

    /**
     * Figure out if the index is a power of 2.
     *
     * @param bitIndex position of the bit (1 = left-most relevant bit), array index 0 is ignored in this assignment.
     * @return True if the bit is a power of 2.
     */
    static boolean isBitPowerOfTwo(int bitIndex) {
        bitIndex = bitIndex ^ (1 << (Integer.SIZE - Integer.numberOfLeadingZeros(bitIndex)-1));
        return bitIndex == 0;
    }

    /**
     * Calculate how many bits the transmitted hamming code should have, given the data bits.
     * @param inputMessage data bits
     * @return length of input message + amount of checker bits
     */
    static int calculateTotalBits(boolean[] inputMessage) {
        int result = inputMessage.length == 1 ? 0 : inputMessage.length -1;

        int crtIndx = 1,
                crtArrayIndx = 1;
        while(crtArrayIndx < inputMessage.length){
            if(isBitPowerOfTwo(crtIndx)){
                result++;
                crtIndx++;
            }else{
                crtArrayIndx++;
                crtIndx++;
            }
        }
        return result;
    }

    /**
     * Calculate the sum of the bits between the indices,
     * left and right are inclusive [left, right].
     *
     * @param inputMessage array of booleans, true = 1 bit, false = 0 bit
     * @param leftInd left most index
     * @param rightInd right most index
     * @return the sum between left and right, based on the truth values in the input message
     */
    static long sumBitsBetweenIndices(boolean[] inputMessage, int leftInd, int rightInd) {
        long sum = 0;

        for(int i = leftInd; i <= rightInd; i++){
            sum += inputMessage[i]? 1: 0;
        }

        return sum;
    }

    /**
     * Decide based on the given sum and the parity if you should place a 1 bit or a 0 bit.
     *
     * @param sum of bits
     * @param isEvenParity is true when parity is even, false otherwise
     * @return whether or not you need to place a 1 or 0 bit
     */
    static boolean calculateCheckBitToPlace(long sum, boolean isEvenParity) {
        boolean result = sum%2 == 1;
        result = result ^ !isEvenParity;
        return result;
    }

}
