```c
struct Employee {
  char *first_name;
  char *last_name;
  int employee_id;
  int ssn;
  float salary;
};

// manually allocating memory
// mark.first_name has type char *
mark.first_name = (char *) malloc(50*size(char));

// manually freeing memory
free(mark.first_name);
mark.first_name = NULL;
```