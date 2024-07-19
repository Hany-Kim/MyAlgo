-- 코드를 입력하세요
select b.BOOK_ID, a.AUTHOR_NAME, DATE_FORMAT(b.PUBLISHED_DATE, '%Y-%m-%d')
from BOOK b
    join AUTHOR a
where b.AUTHOR_ID = a.AUTHOR_ID
    and b.CATEGORY = '경제'
order by b.PUBLISHED_DATE