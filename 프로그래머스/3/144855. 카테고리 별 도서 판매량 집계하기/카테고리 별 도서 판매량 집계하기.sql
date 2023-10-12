-- 코드를 입력하세요
SELECT CATEGORY, SUM(TOTAL_SALES) AS TOTAL_SALES
FROM (
    SELECT A.CATEGORY, (B.SALES) AS TOTAL_SALES
    FROM BOOK A, BOOK_SALES B
    WHERE A.BOOK_ID = B.BOOK_ID AND EXTRACT(YEAR FROM SALES_DATE) = 2022 AND EXTRACT(MONTH FROM SALES_DATE) = 1
)
GROUP BY CATEGORY
ORDER BY CATEGORY ASC