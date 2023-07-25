/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Matthew Lorette Anaya
Hours to complete assignment: 3
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/

 This assignment requires an implementation of a Linear Feedback Shift Register,
 specifically the Fibonacci LFSR.The inital seed (16 bit string) is used and
 left shifted.The shifted bit that is removed is used to perform an XOR operation
 with 3 fixed tap values (at 13, 12 and 10, given in the assignment problem).
 Took the easy route and used the seed string directly wiht an '!=" operation to
 act as the XOR. Inorder to do this I implemented a helper function inorder to return
 a 1 or zero for the bit. substr() was used to act as the leftshift. The bit that is
 returned from the XOR operation is then appended to the substring later to complete the shift.





/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/

Like I stated in the previous question I used the string directly as my register bits
as it was the simplest implementation. each bit can be accessed via [] as the string
is just an array of characters.

 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/

1: just checks to make sure the correct result is returned from the generate function

2: checks to make sure the initialization function throws an invalid argument if the seed
   string is too long or too short.




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
