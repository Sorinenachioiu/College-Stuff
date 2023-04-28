<link rel="stylesheet" type="text/css" href="../styles.css">

<!-- <img src="img/testingWorkflow.png" alt="Effective testing" width="75%"> -->

<!-- <span class="term"> </span>
<span class="definition"> </span>
<span class="important"><span class="exclamation">!</span> </span> </span> -->
# Error Detection and correction

<span class="term"> Error detection and correction </span>
<span class="definition"> - deal with one or multiple bits flipped during transmission from a sender to a receiver.</span>

<span class="term"> Error detection</span>
<span class="definition"> - means that the receiver can identify that there has been an error but they are typically not able to tell which error occurred.<span class="important">As a consequence, the sender has to be given a signal that they have to
retransmit the message</span></span>

<span class="term"> Error correction</span>
<span class="definition"> - allows the receiver to identify the exact bit or bits that have been flipped. <span class="important">The receiver can
hence correct the error without retransmission.</span></span>

### Choosing an error detection/correction algorithm

<span class="important"><span class="exclamation">!</span> Note that no algorithm can detect or correct all errors; error detection and correction only considerably reduce the probability of errors to be forwarded to the next higher layer.</span></span> 

<span class="term"> Amount of redundancy (overhead)</span>
<span class="definition"> - the number of additional bits added. </span>

## 1.Error Detection

### 1.1Parity Bits
<span class="term"> Parity </span>
<span class="definition"> - whether a number (of items) is even or odd. </span>

The algorithm works as follows:
- <span class="term"> Preparation </span>
<span class="definition"> Sender and Receiver agree on the desired parity.</span>
- <span class="term"> Sender </span>
<span class="definition"> has message M. They count the number n of 1s in the message. Then they
append one bit b as follows:</span>
<img src="img/parityBits.png" alt="Effective testing" width="75%">
- <span class="term"> Receiver </span> <span class="definition"> The receiver gets the message M ′, consisting of a message and a parity bit. They count
the number of 1s in M ′. If the parity is as agreed with the sender, the receiver assumes that the
received message is correct. They remove the last bit and process the actual message.</span>

### 1.2Parity Words and Internet Checksum

The algorithm works as follows:
- <span class="term"> Preparation </span>
<span class="definition"> Sender and receiver agree on the block length k, and possibly an algorithm for padding if the message length is not a multiple of k<sup>3</sup>. For parity words, they further agree on the parity.</span> 
- <span class="term"> Sender </span>
<span class="definition"> has the (potentially padded) message M whose length m is a multiple of k. The sender splits the message into l = m/k blocks of length k, such that the first block are the first k bits, the second block are the second k bits and so on. Afterwards, the sender arranges the blocks in a table/matrix, with each block corresponding to one row. \
For the internet checksum, the sender follows the same steps, apart from the use of the bitwise XOR.
Binary addition is used instead to add the blocks, with the most right bit being the least significant bit.
There may be carries. Due to the carries, the result may be longer than k bits. To have a checksum of
exactly k bits when the result is of length k + r, the sender divides the result in two blocks — the first
one of length r and the second one of length k — and adds these two blocks.</span>
- <span class="term"> Receiver </span> <span class="definition"> The receiver gets a message M ′, which they divide into blocks of length k. They compute
the bitwise XOR/addition of all blocks, including the checksum block.
In case of odd parity or 1s complement checksum, the result should be all 1s because the checksum is 1 exactly when the bitwise XOR/addition of the remaining blocks is 0 and vice versa. If a parity
word with even parity is used, the result should be all 0s as we XOR the checksum with itself.
If the computation has the expected result, the receiver removes the checksum and processes the message assuming it is correct.</span>


