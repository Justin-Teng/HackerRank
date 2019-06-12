SELECT CONCAT(name, '(', UPPER(substring(occupation,1,1)), ')')
  AS professions
  FROM occupations
  ORDER BY name;
SELECT CONCAT('There are a total of ', COUNT(occupation), ' ', LOWER(occupation), 's.')
  AS total
  FROM occupations
  GROUP BY occupation
  ORDER BY COUNT(occupation), occupation;
