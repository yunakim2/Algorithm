-- 코드를 입력하세요
SELECT BOOK.BOOK_ID, AUTHOR.AUTHOR_NAME, TO_CHAR(BOOK.PUBLISHED_DATE, 'yyyy-mm-dd') AS PUBLISHED_DATE
FROM BOOK, AUTHOR
WHERE BOOK.AUTHOR_ID = AUTHOR.AUTHOR_ID AND BOOK.CATEGORY = '경제'
ORDER BY PUBLISHED_DATE