TP4-1
SELECT *
FROM OUVRAGES2
WHERE NBPAG>500;

TP4-2
SELECT *
FROM PERSONNES2
WHERE VILLEPERS='Pau'
AND DATINSCRIPT<'01/01/2010';

TP4-3
SELECT NOMPERS, PRENOMPERS
FROM PERSONNES2
WHERE VILLEPERS='Pau' OR VILLEPERS='Lescar';

TP4-4
SELECT NOMPERS
FROM PERSONNES2 P, BIBLIOTHEQUES2 B
WHERE NOMBIB='M�diath�que Andr� Labarr�re'
and P.CODBIB=B.CODBIB;

TP4-5
SELECT DISTINCT NOMPERS, PRENOMPERS
FROM PERSONNES2 P, OUVRAGES2 O, EXEMPLAIRES2 E, PRET2 PR
WHERE (VILLEPERS='Pau' OR VILLEPERS='Billere')
AND NOMAUT='Pennac'
AND PRENOMAUT='Daniel'
AND P.CODPERS= PR.CODPERS
AND PR.CODEX=E.CODEX
AND E.CODOUV=O.CODOUV;

TP4-6
SELECT O2.TITOUV, O2.ANEDIT
FROM OUVRAGES2 O1, OUVRAGES2 O2
WHERE O1.TITOUV='Le trone de fer, l''int�grale 1 : Le donjon rouge'
AND O1.NOMAUT=O2.NOMAUT
AND O1.PRENOMAUT=O2.PRENOMAUT;

SELECT TITOUV, ANEDIT
FROM OUVRAGES2
WHERE (NOMAUT, PRENOMAUT) IN (SELECT NOMAUT, PRENOMAUT
				FROM OUVRAGES2
				WHERE TITOUV='Le trone de fer, l''int�grale 1 : Le donjon rouge');


TP4-7
SELECT CODPERS, NOMPERS, PRENOMPERS
FROM PERSONNES2 P, OUVRAGES2 O
WHERE EXTRACT(YEAR FROM DNAISS)<ANEDIT
AND TITOUV='Ensemble c''est tout';

SELECT *
FROM PERSONNES2
WHERE EXTRACT(YEAR FROM DNAISS)< (SELECT ANEDIT
				  FROM OUVRAGES2
				  WHERE TITOUV='Ensemble c''est tout');

TP4-8
SELECT NOMPERS, PRENOMPERS
FROM PERSONNES2
WHERE CODPERS  IN
	(SELECT CODPERS
	FROM PERSONNES2
	MINUS
	SELECT CODPERS
	FROM PRET2 PR, EXEMPLAIRES2 E, OUVRAGES2 O
	WHERE LANGUE='Anglais'
	AND O.CODOUV=E.CODOUV
	AND E.CODEX=PR.CODEX);

SELECT NOMPERS, PRENOMPERS
FROM PERSONNES2
WHERE CODPERS  NOT IN
	(SELECT CODPERS
	FROM PRET2 PR, EXEMPLAIRES2 E, OUVRAGES2 O
	WHERE LANGUE='Anglais'
	AND O.CODOUV=E.CODOUV
	AND E.CODEX=PR.CODEX);


SELECT NOMPERS, PRENOMPERS
FROM PERSONNES2 P
WHERE   NOT EXISTS
	(SELECT *
	FROM PRET2 PR, EXEMPLAIRES2 E, OUVRAGES2 O
	WHERE LANGUE='Anglais'
	AND O.CODOUV=E.CODOUV
	AND E.CODEX=PR.CODEX
	AND PR.CODPERS=P.CODPERS
	);

SELECT CODPERS, NOMPERS, PRENOMPERS
FROM PERSONNES2
MINUS
SELECT P.CODPERS, NOMPERS, PRENOMPERS
FROM PRET2 PR, EXEMPLAIRES2 E, OUVRAGES2 O, PERSONNES2 P
WHERE LANGUE='Anglais'
AND O.CODOUV=E.CODOUV
AND E.CODEX=PR.CODEX
AND PR.CODPERS=P.CODPERS;

TP4-9
SELECT DISTINCT P.CODPERS, NOMPERS, PRENOMPERS
FROM PRET2 PR, EXEMPLAIRES2 E, OUVRAGES2 O, PERSONNES2 P
WHERE LANGUE!='Francais'
AND O.CODOUV=E.CODOUV
AND E.CODEX=PR.CODEX
AND PR.CODPERS=P.CODPERS;

TP4-10
SELECT DISTINCT TITOUV, NOMAUT, PRENOMAUT
FROM OUVRAGES2 O, EXEMPLAIRES2 E
WHERE O.CODOUV=E.CODOUV
AND EXTRACT(YEAR FROM DATEENTBIB)= ANEDIT+1;

TP4-11
SELECT CODOUV, TITOUV
FROM OUVRAGES2 O
WHERE NOT EXISTS
	(SELECT CODBIB
	FROM BIBLIOTHEQUES2
	WHERE VILLEBIB='Pau'
	MINUS
	SELECT CODBIB
	FROM PRESENT2
	WHERE CODOUV= O.CODOUV);

TP4-12
SELECT COUNT(DISTINCT P.CODPERS)
FROM PERSONNES2 P, PRET2 PR
WHERE P.CODPERS=PR.CODPERS
AND VILLEPERS='Pau';

TP4-13
SELECT NOMPERS, PRENOMPERS
FROM PERSONNES2
WHERE CODPERS NOT IN
	(SELECT CODPERS
	FROM PRET2);

TP5-1
SELECT COUNT(*)
FROM OUVRAGES2;

TP5-2
SELECT COUNT(DISTINCT O.CODOUV)
FROM OUVRAGES2 O, EXEMPLAIRES2 E
WHERE O.CODOUV=E.CODOUV
AND NOMAUT='Pennac'
AND DATEENTBIB<'01/01/2015';

TP5-3
SELECT COUNT(DISTINCT CODPERS)
FROM OUVRAGES2 O, EXEMPLAIRES2 E, PRET2 PR
WHERE O.CODOUV=E.CODOUV
AND E.CODEX=PR.CODEX
AND NOMAUT='Pennac';

TP5-4
SELECT MIN(DATEP)
FROM PRET2;

TP5-5
SELECT NOMPERS, PRENOMPERS
FROM PERSONNES2 P, PRET2 PR
WHERE P.CODPERS=PR.CODPERS
AND DATEP= (SELECT MIN(DATEP)
	    FROM PRET2);

TP5-6
SELECT SUM(MTCOTIS)
FROM PERSONNES2 P, BIBLIOTHEQUES2 B
WHERE P.CODBIB=B.CODBIB
AND NOMBIB='M�diath�que Andr� Labarr�re';

TP5GroupBy-1
SELECT NOMAUT,PRENOMAUT, COUNT(*)
FROM OUVRAGES2
GROUP BY NOMAUT, PRENOMAUT;

TP5GroupBy-2
SELECT NOMBIB, VILLEBIB, COUNT(DISTINCT NOMAUT||PRENOMAUT)
FROM BIBLIOTHEQUES2 B, PRESENT2 P, OUVRAGES2 O
WHERE B.CODBIB=P.CODBIB
AND P.CODOUV=O.CODOUV
GROUP BY B.CODBIB,NOMBIB, VILLEBIB;

TP5GroupBy-3
SELECT NOMAUT, PRENOMAUT, COUNT(CODEX)
FROM OUVRAGES2 O, EXEMPLAIRES2 E
WHERE O.CODOUV=E.CODOUV
AND ANEDIT=2016
GROUP BY NOMAUT, PRENOMAUT;

TP5GroupBy-4
SELECT O.CODOUV, TITOUV, COUNT(*)
FROM OUVRAGES2 O, EXEMPLAIRES2 E, PRET2 PR
WHERE O.CODOUV=E.CODOUV
AND E.CODEX=PR.CODEX
GROUP BY O.CODOUV, TITOUV;

TP5GroupByHaving-1
SELECT NOMPERS, PRENOMPERS
FROM PERSONNES2 P, PRET2 PR
WHERE P.CODPERS=PR.CODPERS
GROUP BY P.CODPERS, NOMPERS, PRENOMPERS
HAVING COUNT(CODEX)>5;

TP5GroupByHaving-2
SELECT O.CODOUV, TITOUV
FROM OUVRAGES2 O, EXEMPLAIRES2 E
WHERE O.CODOUV=E.CODOUV
AND LANGUE='Anglais'
GROUP BY O.CODOUV, TITOUV
HAVING COUNT(CODEX)>10;

TP5GroupByHaving-3
SELECT O.CODOUV, TITOUV
FROM OUVRAGES2 O, PRESENT2 P
WHERE O.CODOUV=P.CODOUV
GROUP BY O.CODOUV, TITOUV
HAVING COUNT(CODBIB) > (SELECT COUNT(CODBIB)
			FROM OUVRAGES2 O, PRESENT2 P
			WHERE O.CODOUV=P.CODOUV
			AND TITOUV='La d�licatesse du homard');


TP5GroupByHaving-4
SELECT P.CODPERS, NOMPERS, PRENOMPERS
FROM PERSONNES2 P, PRET2 PR
WHERE P.CODPERS=PR.CODPERS
GROUP BY P.CODPERS, NOMPERS, PRENOMPERS
HAVING COUNT(CODEX)=(SELECT MAX(COUNT(CODEX))
		     FROM PRET2
		     GROUP BY CODPERS);
