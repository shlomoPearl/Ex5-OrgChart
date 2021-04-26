<div dir="rtl" lang="he">

# עץ בינארי - שלב א

בקורס קודם למדתם (או הייתם אמורים ללמוד) על עצים בינאריים, ועל שלושת הדרכים לסייר בהם:
preorder, inorder, postorder.
במטלה הזאת המטרה היא לממש עץ בינארי עם איטרטורים שיכולים לעבור עליו בכל שלושת הסדרים.

שם המחלקה: `BinaryTree`.
השיטות הדרושות (ראו בקובץ [Demo.cpp](Demo.cpp) לפרטים):

* `add_root` - מקבלת קלט אחד ושמה אותו בשורש של העץ. אם כבר יש משהו בשורש, הוא מוחלף.
* `add_left` - מקבלת שני קלטים: הקלט הראשון מציין דבר שכבר קיים בעץ. הקלט השני מציין דבר חדש שיש להוסיף בתור הילד השמאלי שלו (אם כבר יש לו ילד שמאלי - יש להחליף את התוכן שלו). 
* `add_right` - כנ"ל, רק שהתוספת היא בתור הילד הימני.
* `begin_preorder()`, `end_preorder()` - מחזירות איטרטורים לצורך מעבר בסדר preorder (אב - שמאל - ימין).
* `begin_inorder()`, `end_inorder()` - מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - אב - ימין).
* `begin_postorder()`, `end_postorder()` - מחזירות איטרטורים לצורך מעבר בסדר inorder (שמאל - ימין - אב).
* אופרטור פלט - מדפיס את העץ בפורמט הגיוני כלשהו לבחירתכם.

פרטים:

* העץ לא בהכרח מסודר לפי סדר עולה, ולא בהכרח מאוזן. סדר הנתונים בעץ הוא לפי האופן שבו הם מוכנסים. ראו בתוכנית הדוגמה.
* בפונקציות add_left, add_right, אם הקלט הראשון לא קיים בעץ - יש לזרוק חריגה. אם הוא קיים פעמיים או יותר - יש לבחור אחת משתי האפשרויות ולהוסיף לשם (בבדיקות האוטומטיות אל תכניסו מצבים כאלה, כדי שהתוצאה תהיה חד-משמעית).


בשלב א עליכם לכתוב: 

* קובץ כותרת הכולל את כל הפונקציות הדרושות (ללא מימוש). שימו לב: הכותרות צריכות להיות נכונות בהתאם למה שנלמד בהרצאות - מומלץ לחזור על החומר לפני שמתחילים לכתוב.
* בדיקות מקיפות לכל הפונקציות הדרושות. אין צורך לכתוב בדיקות אוטומטיות לאופרטור הפלט.


כיתבו את כל הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות:

<div dir='ltr'>

    make demo && ./demo
	make test && ./test

</div>

מומלץ גם להריץ `make tidy`, `make valgrind`.

אין לשנות את הקבצים הנתונים, אלא רק להוסיף קבצים חדשים.

יש לפתור את המטלה באופן עצמאי.

* מותר להתייעץ עם סטודנטים אחרים או לחפש מידע באינטרנט;
אסור להעתיק קטעי-קוד שלמים מסטודנטים אחרים או מהאינטרנט.
* יש לדווח על כל עזרה שקיבלתם, מסטודנטים אחרים או מהאינטרנט, בהתאם ל[תקנון היושר של המחלקה](https://www.ariel.ac.il/wp/cs/wp-content/uploads/sites/88/2020/08/Guidelines-for-Academic-Integrity.pdf).

</div>
