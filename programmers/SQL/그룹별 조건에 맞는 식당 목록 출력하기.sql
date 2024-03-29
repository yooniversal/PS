SELECT M.MEMBER_NAME, R.REVIEW_TEXT, DATE_FORMAT(R.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
FROM REST_REVIEW AS R
JOIN MEMBER_PROFILE AS M ON M.MEMBER_ID = R.MEMBER_ID
WHERE R.MEMBER_ID = (
    SELECT R.MEMBER_ID
    FROM MEMBER_PROFILE AS M
    JOIN REST_REVIEW AS R ON M.MEMBER_ID = R.MEMBER_ID
    GROUP BY M.MEMBER_ID
    ORDER BY COUNT(M.MEMBER_ID) DESC LIMIT 1
)
ORDER BY R.REVIEW_DATE, R.REVIEW_TEXT