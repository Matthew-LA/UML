OA/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Matthew Lorette Anaya


Hours to complete assignment: 5

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
	Using the Karpus-Strong algorithm, the assignment was to write a program simulating the plucking of a guitar string and get a better understanding of cpplint using exceptions and unit testing. I complished everything previously stated.


/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
	With the use of boost I was able to check the circular or ring buffer and the use of invalid input cases. Using main I manipulated the circular buffer to test random edge cases.


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

runtime_error
	Thrown when there are attempts to ensue or duque a circular buffer 
	when not possible i.e. when its full or empty.

	if (isFull()){
        throw std::runtime_error("enqueue: can't enqueue to a full buffer");
     }

	if (isEmpty()){
        throw std::runtime_error("dequeue: can't dequeue an empty buffer");
    }

invalid_argument
	Thrown when negative numbers are inputed, as Circular Buffer cannot contain such.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
	I did complete the whole assignment successfully. All parts are working. I know this
as I implemented custom testing in main along with the Boost tests. These custom test outputs can be
seen when using the ./main.out command.


/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
	My circular buffer has passed the unit tests. I know this as the tests that are suppose to pass
pass, pass and the ones that should fail, fail.


/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
	I implemented circular buffer using a vector instead of an array. Though this class template for sequence 
containers uses more memory than an array, it implements many things that make it easier to manage like built in 
functions such as resize. If circular buffer becomes quite large this could be a reason to switch to using an array,
but for this implementation, I think it works well. 


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
