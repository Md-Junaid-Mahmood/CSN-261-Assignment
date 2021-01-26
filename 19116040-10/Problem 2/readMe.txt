Below is the sample input taken during the testing of the code:

11
2
i 5
i 9
i 3
i 7
i 1
i 2
i 8
i 6
i 0
i 4
d 9

Now, given the minimum number of child pointers (say t), maximum number of child pointers is given by 2*t and consequently, maximum number of keys can be given by 2*t - 1

Following choices may affect the total number of merge operations and split operations performed during the program execution:

1) Given a particular value of t (minimum number of child pointers), whether to completely fill the root before proceeding to next level or fill only the minimum required elements in the root and proceed to next level

2) The choice of element of a node (if there are many possible choices) during merge operation and split operation 

