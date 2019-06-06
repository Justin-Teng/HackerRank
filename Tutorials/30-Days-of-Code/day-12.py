class Student(Person):
    #   Class Constructor
    #   
    #   Parameters:
    #   firstName - A string denoting the Person's first name.
    #   lastName - A string denoting the Person's last name.
    #   id - An integer denoting the Person's ID number.
    #   scores - An array of integers denoting the Person's test scores.
    #
    # Write your constructor here
    def __init__(self, firstName, lastName, idNumber, scores):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber
        self.scores = scores

    #   Function Name: calculate
    #   Return: A character denoting the grade.
    #
    def calculate(self):
        avg = sum(self.scores) / len(self.scores)
        if avg >= 90: print("Grade: O")
        elif avg >= 80: print("Grade: E")
        elif avg >= 70: print("Grade: A")
        elif avg >= 55: print("Grade: P")
        elif avg >= 40: print("Grade: D")
        else: print("Grade: T")
        quit()
