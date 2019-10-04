# Seven_Segment_Converter

Simple program written in C that accepts user input of integers and converts them into their seven-segment equivalent. Currently set up to ignore anything other than integers (i.e. letters, special characters). Also has a set maximum number of digits it will convert (10) but can be adjusted to convert any number of integers using the declared constant at the beginning of the class. 

Completed as part of an assignment for a course. 


<br>



<h2> Notes </h2>

<br>

<p>
  Seven-Segment conversion uses the following format to activate/deactivate segments of each number:
  
  ```
    ___0___
   |       |
  5|       |1
   |___6___| 
   |       |
  4|       |2
   |___3___|
   
  ```
  
  <br>
  
  Each seven-segment digit has a corresponding array (row) that contains the binary values of the segments that are active and/or inactive to correctly display the digit (i.e. represented by 0's for off and 1's for on). The segments are broken down below. 
  
```C
  
 const int segments[10][7] = {
 /* { 0 1 2 3 4 5 6 }  ===> Segment Columns  */
    { 1,1,1,1,1,1,0 }, // 0
    { 0,1,1,0,0,0,0 }, // 1
    { 1,1,0,1,1,0,1 }, // 2
    { 1,1,1,1,0,0,1 }, // 3
    { 0,1,1,0,0,1,1 }, // 4
    { 1,0,1,1,0,1,1 }, // 5
    { 1,0,1,1,1,1,1 }, // 6
    { 1,1,1,0,0,0,0 }, // 7
    { 1,1,1,1,1,1,1 }, // 8
    { 1,1,1,0,0,1,1 }  // 9
 };
  
```
  
</p>

<br>

<p>
  
  Each integer is read, converted, and stored into another two-dimensional array called `digits` that is 3 rows high and as wide as necessary to fit the number of digits the user wishes to convert. This program currently has a maximum number of accepted digits set to 10. Each digit requires 4 columns of spacing (3 for the segments and 1 trailing space for generic spacing). With 10 maximum digits requiring 4 columns each, the array required 40 total columns in order to fit the maximum number of digits. Below is an example of the required spacing:
  
  
  ```
     0 1 2 3 0 1 2 3 0 1 2 3 0 1 2 3
  0 [ ___     ___             ___   ]
  1 [ ___|   |   |       |   |___|  ] ... etc
  2 [|___    |___|       |   |___|  ]
  
  ```


<br>


  In order to correctly place the "activated" segments into their corresponding location in the array, a switch case was used to determine the current position, corresponding segment, and placement location within the `digits` array. (Shown in the following function). Once populated, the array (i.e. seven-segment representation) is ready to display to the user.
  
  
  ```C
  
  void process_digit(int digit, int position) {
     // Accounts for the 7 segments that must display for each number
     for (int i = 0; i < 7; i++) {
        
        // Uses positional assignment to correctly place the bar in the correct location of the 7 segment digit
        if (segments[digit][i]) {
            switch (i) {
                case 0: digits[0][1 + position] = '_';
                    break;
                case 1: digits[1][2 + position] = '|';
                    break;
                case 2: digits[2][2 + position] = '|';
                    break;
                case 3: digits[2][1 + position] = '_';
                    break;
                case 4: digits[2][0 + position] = '|';
                    break;
                case 5: digits[1][0 + position] = '|';
                    break;
                case 6: digits[1][1 + position] = '_';
                    break;
           }
        }
     }
  }
  
  ```

</p>




















