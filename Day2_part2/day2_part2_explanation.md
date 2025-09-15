# Step-by-Step Process

## 1. Store and Read Data
Store the data in `data.txt`. In the `getTestDataFrmFile` function, read `data.txt` line by line and call the `isSafe` function to check whether each line meets the requirements.

---

## 2. Initial Check with day2_part1
Use `day2_part1` to determine whether the line meets the condition. If it does, increment the count by 1 and continue to the next line.

---

## 3. Further Check with doubleCheckSafe
If the line does not meet the condition, call the function `int doubleCheckSafe(int *array, int num)` to perform further checking.
``` C
while (fgets(line, sizeof(line), fp)) {
        int numbers[100];
        int n = 0;
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            numbers[n++] = atoi(token);
            token = strtok(NULL, " \t\n");
        }
        if (isSafe(numbers,n) == 0) {
            if (doubleCheckSafe(numbers,n) == 1) {
                sum += 1;
            }
        } else {
            sum += 1;
        }
    }
```

---

## 4. Generate Subarrays and Check
For each array passed to `doubleCheckSafe`:

1. Iterate through the array.  
2. Each time, remove one element from the array to form a new subarray.  
3. Pass this new subarray to the `isSafe` function in `day2_part1` to check if it meets the condition.  
4. If a subarray meets the condition, stop the loop and continue reading the next line in `getTestDataFrmFile`.  
5. If it does not meet the condition, remove the next element and repeat until all elements have been removed.  
6. If no subarray satisfies the condition after iterating through the entire array, the original array is considered not meeting the condition.

``` C
int doubleCheckSafe(int *array, int num){
    int flag = 0;
    for (int index = 0; index <= num - 1; index++) {
        int newArr[num - 1];
        int* p = newArr;
        for (int innerIndex = 0; innerIndex <= num -1; innerIndex++) {
            if (innerIndex != index) {
                *p = *(array + innerIndex);
                p++;
            }
        }
        if (isSafe(newArr, num - 1) == 1) {
            flag = 1;
            break;
        }
    }
    return flag;
}
```
---

## 5. Repeat for All Lines
Repeat steps 2–4 for each line in `data.txt` until all lines have been processed.
