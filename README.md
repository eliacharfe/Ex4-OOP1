# Ex4-OOP1
2nd year - sem 1

תרגיל 4: SFML

סלומון דמה 314010919
אלישר פייג 302278338

הסבר כללי:

בתרגיל היה עלינו לממש את משחק SFML- במשחק מוצג לוח שעליו יש:
שחקן: @  
(שחקן כאשר נמצא על סולם: S 
שחקן כאשר כאשר נמצא על מוט: ^)
אויבים: %
גבולות ורצפה: #
מטבעות: *
סולמות: H 
מוטות:  - 

תיאור המשחק:
על החלון המוצג יש תפריט עם אובייקים ומשטח ציור.
את האובייקטים ניתן לצייר על לוח הציור ע"י לחיצה עם העכבר ואז לחיצה על משטח הציור.

מטרת המשחק-
מטרת המשחק הוא ליצור לוח משחק ע"י האובייקטים המוצגים בתפריט. 

  תיכון (Desing):

המשחק מנוהל ע"י Window mangaer 
המשחק מחולק למחלקות : Board Editor, Game object, menu
וקובץ  אהדר Consts.


רשימת הקבצים שיצרנו:

Window mangaer h/cpp
מנהל את המשחק ואת הצג המוצג לנו בחלון ע"י המחלקות האחרות.

Game object h/cpp 
מחלקה זו היא זו שמחזיקה את הנתונים של כל אובייקט וטוענת את את התמונות של האובייקטים.

menu h/cpp 
מחלקת התפריט היא זו שמחזיקה את כל האובייטקים של המשחק ע"י מערך של מטיפוס Game object 
היא מציגה את כל האובייקטים המצויינים לעיל. 

Board Editor h/cpp 
מחלקת הלוח היא המחלקה אשר אחראית על פתיחת הקבצים, שמירת הקבצים והחזקת הנתונים המתקבלים
מתוך הקבצים. הנתונים משתנים בהתאם למשחק. כאשר המשתמש לוחץ על הכפתור שמור הקובץ
מתעדכן.

Consts.h
מחזיקה נתונים גלובלים המשמשים אותנו במשחק ובצג המוצג בחלון

אלגוריתמים הראויים לציון:
**********************************************************
***********************************************************

תזוזות לא חוקיות: לא ניתן למקם את השחק על אובייקטים אחרים,כגון סולם, קיר ומוט

באגים ידועים:
אין

