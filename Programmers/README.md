### Note

1. `floating point exception`

   `a % b` 혹은 `a / b`에서 `b = 0`인 경우 발생 가능

2. 알파벳 `char ch;`를 일괄적으로 대문자 혹은 소문자로 변경

   (1) 대문자로 : `ch = ch & ~(32);` 

   (2) 소문자로 : `ch = ch | 32;`

