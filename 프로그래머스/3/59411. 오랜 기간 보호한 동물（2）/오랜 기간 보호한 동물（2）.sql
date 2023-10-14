SELECT ANIMAL_ID, NAME
FROM (SELECT A.ANIMAL_ID, A.NAME, (B.DATETIME -  A.DATETIME)
FROM ANIMAL_INS A INNER JOIN ANIMAL_OUTS B ON A.ANIMAL_ID = B.ANIMAL_ID
ORDER BY 3 DESC )
WHERE ROWNUM <= 2