SELECT IF(A+B<=C OR A+C<=B OR B+C<=A, 'Not A Triangle',
          IF(A=B AND B=C, 'Equilateral',
             IF(A!=B AND B!=C AND A!=C, 'Scalene',
                'Isosceles')))
FROM Triangles;
