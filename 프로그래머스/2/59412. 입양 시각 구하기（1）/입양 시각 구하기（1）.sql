-- 코드를 입력하세요
SELECT HOUR, COUNT(*)
FROM (SELECT TO_CHAR(DATETIME, 'HH24') HOUR FROM ANIMAL_OUTS)
WHERE HOUR BETWEEN 9 AND 19
GROUP BY HOUR
ORDER BY HOUR