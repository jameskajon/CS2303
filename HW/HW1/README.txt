How to Run:
cd to the location of PA1.c
compile using gcc (e.g.: gcc PA1.c)
run the compiled file (e.g.: ./a.out)

Loop Invariants:
printCalendar : The condition is initaly true because m is initialized to 0 and checked if less than 12. It will stay true until m is 11 which represents the month December.
printMonth 1st loop : The condition is true only if indents are needed. The loop will terminate when the number of indents done is equal to the id of the starting day.
printMonth 2nd loop : The condition is initially true because each month has more than 0 days. It will eventually terminate when the day is equal to the days in the month.

Summary:
As outlined, main asked for a year to be input. If the year is zero or less, the program will print out that it was given an invalid input and end, otherwise it will continue and print the calendar. main calculates the day of the week that year starts on with calculateStartingWeekDay (see calculateStartingWeekDay explination) then calls printCalendar. printCalendar prints the title of the calendar then uses printMonth to print the 12 months for that year. Each time printMonth is called it returns the starting day of the week for the next month and printCalendar feeds that to the next month. All the values of the day of the week and month are integer ids. The days of the week are the numbers 0 to 6 inclusive with 0 being Sunday, 1 being Monday, ..., and 6 being Saturday. The months are represented by the numbers 0 to 11 inclusive with 0 being January, ..., and 11 being December. As soon as printMonth is called, it calls printMonthName which no only tells print month how many days are in the month based on the month id but also prints a lable for that month. Now with the number of days, printMonth prints the lable for the days of the week, prints the correct number of indents (aka the id of the starting day) for the first day, starts a loop from 1 to the number of days in the month inclusive. The loop prints the date with the proper formating including a line break at the end of every loop. The calendar is compleated with these iterative calles to printMonth from printCalendar.

calculateStartingWeekDay Explination:
From Davies, Joshua, 2012, January 16, commandlinefanatic.com/cgi-bin/showarticle.cgi?article=art009
Since each year has 365 days and 365%7=1 the day of the week would increase by one every year (starting on Monday one year and Tuesday the next). Since it happends that the year 0 would start on a Sunday and that is what I use as zero, without leep years, the given year mod 7 would give the starting day. With leep years, the amout of leep days between the year zero and the given year must be added to the year. It's basicly count the days since Jannuary 1st in the year 0 which was a Sunday and mod it by 7 (with a few shortcuts).

