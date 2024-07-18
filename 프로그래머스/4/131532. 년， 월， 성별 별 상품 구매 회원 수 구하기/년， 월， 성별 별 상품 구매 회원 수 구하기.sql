-- USER_INFO 테이블과 ONLINE_SALE 테이블에서 년, 월, 성별 별로 상품을 "구매한 회원수를 집계"
-- 결과는 년, 월, 성별을 기준으로 오름차순 정렬해주세요. 
-- 이때, 성별 정보가 없는 경우 결과에서 제외해주세요
SELECT YEAR(SALES_DATE) as YEAR, MONTH(SALES_DATE) as MONTH, ui.GENDER as GENDER, COUNT(DISTINCT ui.USER_ID) as USERS
FROM USER_INFO ui
    JOIN ONLINE_SALE os
    ON ui.USER_ID = os.USER_ID
WHERE NOT ui.GENDER IS NULL
GROUP BY YEAR(SALES_DATE), MONTH(SALES_DATE), ui.GENDER