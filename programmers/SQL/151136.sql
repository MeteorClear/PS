/*
https://school.programmers.co.kr/learn/courses/30/lessons/151136
평균 일일 대여 요금 구하기

CAR_RENTAL_COMPANY_CAR 테이블
자동차 종류가 'SUV'
평균 일일 대여 요금을 출력
평균 일일 대여 요금은 소수 첫 번째 자리에서 반올림
컬럼명은 AVERAGE_FEE 로 지정
*/
SELECT ROUND(AVG(DAILY_FEE)) AS AVERAGE_FEE 
FROM CAR_RENTAL_COMPANY_CAR 
WHERE CAR_TYPE = 'SUV';
