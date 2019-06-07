SELECT
    CASE
        WHEN Grades.Grade < 8
        THEN NULL
        WHEN Grades.Grade >= 8
        THEN Students.Name
    END,
    Grades.Grade,
    Students.Marks
    FROM Students
    INNER JOIN Grades
    ON Students.Marks
    BETWEEN Grades.Min_Mark AND Grades.Max_Mark
    ORDER BY Grades.Grade DESC, Students.Name ASC, Students.Marks ASC
