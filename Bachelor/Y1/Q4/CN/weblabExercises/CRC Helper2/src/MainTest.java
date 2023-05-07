import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class MainTest {
    // / This represents 0b1011
    boolean[] booleanInputMessage = new boolean[] { false, true, false, true, true };

    /**
     *  Data bits output for 0b1011:
     *  xxxxx  xxxxx  xxxxx     1  xxxxx      0     1     1
     * [false, false, false, true, false, false, true, true]
     */
    boolean[] placedDataBits = new boolean[] { false, false, false, true, false, false, true, true };

    @Test
    public void testPutDataBitsInPosition() {
        boolean[] solutionOutput = Main.placeDataBits(booleanInputMessage, 7);
        System.out.println(solutionOutput);
        System.out.println(placedDataBits);
        assertEquals(Arrays.toString(placedDataBits), Arrays.toString(solutionOutput));
    }

    // @Test(timeout = 100)
    // public void calculateCheckBits() {
    //     //boolean[] inputMsg = new boolean[]{false, true, false, true, true}; /// 0b1011
    //     boolean[] placedDataBits = new boolean[]{false, false, false, true, false, false, true, true}; /// placed
    //     boolean[] expectedOutput = new boolean[]{false, true, true, false, false, false, false, false}; /// check bits
    //     boolean[] solutionOutput = Solution.calculateCheckBits(placedDataBits, 7, true);
    //     assertEquals(Arrays.toString(expectedOutput), Arrays.toString(solutionOutput));
    // }

    @Test
    public void testHammingCode() {
        assertEquals(0b1010101, Main.calculateHammingCode(0b1101, true));
        assertEquals(0b1110001, Main.calculateHammingCode(0b1001, false));
    }
}
