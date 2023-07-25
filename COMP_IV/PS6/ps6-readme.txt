/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name: Matthew Lorette Anaya

Hours to complete assignment: 12
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

Using probabilistic analysis on text to determine the next character/s in 
a sequence of length k words called kgrams is the Markov Model's name of the game. 
With the input of a string and order k the RandWriter class maps each of the kgrams 
in the string to it's following character and frequency. With the given kgram it can 
then generate a new string based on the probability of each of the following characters.
Using this function, the TextWriter class is able to analyze words in text file and 
generate a pseudorandom string of L length.

Test:
	./TestWriter   


  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

RandWriter makes use of the Mersenne Twister random number generator in
the kRand() function instead of srand.
It also makes use of maps containing a kgram key and a map of
characters and their frequency as the respective value.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

A map is set up by the RandWriter's constructor that is able to be displayed 
similar to a table. This table holds each kgram, kgram's frequency, each of the
following characters, following character's frequency, and the following character's  
probability. kRand() is used as a helper function by the generate function, in order to 
select a random next character from a kgram string when
building a new string out of previously generated characters.



/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

I believe so.


/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

Yes, the implementation passes the BOOST tests.


 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/

TextWriter catches and handles the exceptions thrown by the RandWriter class'
functions and constructor.



 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/


/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

