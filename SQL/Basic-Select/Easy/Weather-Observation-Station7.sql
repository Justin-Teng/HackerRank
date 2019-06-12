SELECT DISTINCT city FROM station
  WHERE substr(city, CHAR_LENGTH(city), 1) IN ('a', 'e', 'i', 'o', 'u');
