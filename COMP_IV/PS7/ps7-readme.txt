/**********************************************************************
 *  readme.txt template                                                   
 *  PS7 Kronos 
 **********************************************************************/

Name: Matthew Lorette Anaya


Hours to complete assignment: 7


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I believe so. I know this as the implementation successfully produces the
document specified by the pdf.


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/

regex: "^\\d{4}[-](0[1-9]|1[012])[-](0[1-9]|[12][0-9]|3[01])\\s\\d{2}[:]\\d{2}
[:]\\d{2}"

Considering the boot messages were constant, it made it possible to be scanned
without the need of a regex. So, I only needed one to retrive the time and date
of each boot started line and done line.


/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
Depeneding on the message scanned within the log file, read line by line,
by the progam, it determines if a boot has started or finised. If the program
runs accross a start message the date and time are saved.  After that, once
a boot finished message is scanned, the date and time is saved once again. The
total boot time from start to done is saved as well. All this information is then
gathered and saved to a .rpt file. This file contains all successful and
unsuccessful boots.



/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/





/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/


