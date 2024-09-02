/*
https://school.programmers.co.kr/learn/courses/30/lessons/133025
과일로 만든 아이스크림 고르기

상반기 아이스크림 총주문량이 3,000보다 높으면서 
아이스크림의 주 성분이 과일
아이스크림의 맛을 총주문량이 큰 순서대로 조회
*/
SELECT FLAVOR
FROM FIRST_HALF
WHERE TOTAL_ORDER > 3000 AND
      FLAVOR IN (SELECT FLAVOR
                 FROM ICECREAM_INFO
                 WHERE INGREDIENT_TYPE = 'fruit_based')
ORDER BY TOTAL_ORDER DESC;
