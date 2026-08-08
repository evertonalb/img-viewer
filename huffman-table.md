# Decoding a Huffman code segment
This document explains how to decode a huffman table from a JPEG binary, as described by the\
ITU-T T.81 standard.

## Marker
The marker Define Huffman Table (DHT) is 0xFFC4, and it is the first thing in the Huffman table definition.

## BITS
It is followed by the BITS list, a list of 16 bytes telling us how many symbols are there that correspond\
to each possible code length:

L1 - L2 - L3 - L4 - ... - L16

Where Li is one byte meaning that there are Li codes with i bits.

## HUFFVAL
After the BITS list we have HUFFVAL, which is a list of all symbols with an associated huffman code.

## Decoding algorithm
With BITS and HUFFVAL we produce two tables (arrays, really): HUFFSIZE and HUFFCODE. HUFFSIZE has a list of code lengths\
and HUFFCODE contains a list of Huffman codes correponding to those lengths.

### Size Table (HUFFSIZE)

![Generate HUFFSIZE algorithm](./huffsize.png)

The procedure above goes through the BITS list, starting at the index 1 (the first one). For each index I\
in BITS, the procedure will create BITS[I] elements in the HUFFSIZE list (initially empty) each one holding\
the value I -- meaning that there are BITS[I] elements with an I bits long Huffman code.
Lastly the procedure appends to HUFFSIZE a null element as a sentinel value, but also saves that index in the\
variable LASTK (the last K index in HUFFSIZE). However, keep in mind that HUFFSIZE[K] is not a valid entry.

### Codes Table (HUFFCODE)

<img-generate_codes_table>

This algorithm first assigns HUFFCODE[0] with the code 0 (because there must be at least one one-bit-long\
code in a Huffman encoding). After that, it keeps track of the current code length (SI), the current HUFFCODE\
index (K) and the current code (CODE, initially zero but becomes 1 after the first assignment).

The procedure will always check if the current SI matches the current HUFFSIZE[K]. If that happens, HUFFCODE[K]\
receives the value stored in CODE, and the variables CODE and K get incremented. Otherwise, CODE is shifted left\
by one and SI gets incremented until it matches HUFFSIZE[K].

Whenever HUFFSIZE[K] becomes zero, the algorithm stops, since that is the sentinel value that was set in the\
previous procedure.

With the two tables it is possible to decode the values, knowing the the symbol HUFFCODE[K] with size HUFFSIZE[K]\
corresponds to the symbol HUFFVAL[K].

# Encoding tables

<img-order_codes>

For encoding, the HUFFSIZE and HUFFCODE are reordered into two new tables EHUFSI and EHUFCO according to the values stored\
in HUFFVAL. This procedure uses the variable K (starting at zero) to go through all the encoded symbols. Using HUFFCODE[K]\
as the index I, for EHUFCO and EHUFSI, it assigns EHUFSI[I] and EHUFCO[I] with HUFFSIZE[K] and HUFFCODE[K], respectively.

