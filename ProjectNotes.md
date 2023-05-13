TODO demà: 
- Afegir el text amb UV un cop superat el nivell pel codi de nivell final 
- Fer nivell caixa forta 
- Fer nivell porta al nord


## Mecàniques disponibles:
- interacció al toc de pantalla
- interacció a la inclinació de la targeta
- interacció a la rotació del mobil
- interacció entre llums virtuals
- detecció d'inclinació del mobil
- detecció punts cardinals

## Mecàniques per implementar obligatories
- col·lisió entre objectes ( fer-la funcional, per exemple que en interactuar, un objecte agafi a l'altre)

## Història ( context ) de la partida: 
- Estàs a l'any 2150, en un univers on existeix el món real i el virtual. 
- Cada persona ( o algunes privilegiades ) del mon real tenen la capacitat de "reencarnar-se" en el mon virtual, que ja és tan desenvolupat que ja ha adoptat el mateix model de mon que el real ( hi ha feines, famílies.. ). 
- El teu personatge ha quedat atrapat en una habitació "real" i no ets capaç de "reencarnar-t'hi", l'has d'intentar ajudar des del mon real i la única manera que tens d'interactuar-hi és amb unes targetes que t'ha enviat el teu personatge i contenen objectes del mon virtual rellevants per a ser rescatat.   


### "OBJECTES"
- inventari virtual: eines que tens " dins el mobil ". E.g. la llanterna principal, guardarà la clau un cop l'agafis de dins la caixa forta, una clau anglesa per exemple que hagis d'arrastrar a un cargol, qualsevol cosa que necessiti ser arrastrada des de la pantalla. 

- inventari real: cartes que s'identificaràn com a eines que en principi has de "portar a sobre" i utilitzar movent-la amb la ma. E.g. una bruixula, la llum ultravioleta, podria intentar tenir un rellotge de mà i fer un puzle relacionat amb l'hora, etc. 


### Fil de la partida ( esquema )
- Has de proporcionar-li una porta virtual ( targeta que ha d'anar en vertical ), el teu personatge ha de sortir cap al nord ( per exemple ), així que quan la porta s'obri, només mostrarà el mon virtual 
- Pot haver-hi un objecte molt pesat perquè el mogui el teu personatge virtual, però com que tens la capacitat de moure l'orientació inclinant les targetes, el podràs apartar inclinant la targeta
- A l'habitació hi haurà una caixa forta que conté la clau de la porta, i només es pot obrir girant la rodeta amb la inclinació del mobil, la combinació haurà de ser trobada amb els puzles anteriors.
- Caldrà donar il·lumianció a algun objecte virtual per trobar la combinació de la caixa forta, per això el teu personatge t'ha donat una llenterna, però primer caldà encendre-la apretant un botó. 
- M'agradaria utilitzar la emprempta dactilar per haver d'obtenir un digit de la contrasenya final. ( inviable )
- Seria guai tenir una arma i que vagin apareixent "dolents" volant per la zona i els hagis de disparar ( sinó, et fan mal i es pot morir la partida), seria fer spawn a l'espai random però.. molt dificil

### Fil de la partida 
- Caldrà escanejar una imatge d'inici de partida, en aquesta apareixerà una criatura que explicarà el problema

### Puzles: 

0.  Encendre la llum general: ( NO ÉS DEL TOT NIVELL, és un aspecte superior als nivells )
    - La llum està apagada, tens una eina "llanterna" al mobil, si l'encens i t'apropes molt als objectes, pots intuïr què son, però no interactuar amb ells ( excepte el botó d'encendre la llum). 
    - Quan trobes l'objecte encarregat, el podràs clicar des de la pantalla del mobil i encendre la llum general que et permetrà veure bé tots els objectes. ( això ja ens pot donar un número). Aquesta llum s'apagarà cada X segons i caldrà tornar a encendre-la manualment, en un punt de partida estaria bé poder posar un objecte pesant sobre del botó i que quedi permanentment encès ( per jugar amb timers de Unreal engine ).

1. LLum ultravioleta: (NIVELL 1)
    Algun objecte amaga alguna cosa.. sembla que una llum ultraviuleta revelaria el que amaga.
    - Tens una lampara a la què li falten piles, has de combinar la lampara i les piles a la mateixa pantalla perquè aquestes s'introdueixin a la lampara. Un cop encesa, col·locar-la a prop de l'objecte revelarà el que amaguen. ( en aquest cas, seria un numero de la combinació de la caixa forta final ).
    NOTES: com fer que "amagui alguna cosa?". Mostrar la meitat del numero? Que tinguin un color diferent a la resta de textures..? Que simplement sigui blanc? Que continui apagat?


2. Llum lasers: (NIVELL 2)
    Tens una targeta que mostra amb un terre amb parets, un punt vermell, i un laser engegat. Tens una targeta que representa un mirall, caldrà que col·loquis el mirall de manera correcte perquè el reboti al punt vermell i d'aquesta manera obtinguis un numero de la combinació final. Intentar desglosar el "mapa central" amb diferents parts de manera que pugui posar objectes blocants movibles que calgui moure amb la inclinació de la targeta per tal que el laser pugui arribar al destí.

3. Caixa forta: ( NIVELL )
    - Té la tipica "roda". Amb la rotació del mobil caldrà entrar els digits obtinguts en els puzles anteriors. Això permetrà obtenir una clau. 

4. Porta:
    - Una carta representarà una porta ( grossa, aquesta seria la més interessant d'utiltzar l'arpin..). Tindrà varies condicions per poder ser utilitzada: haurà d'estar a un pla detectat, amb la carta posicionada verticalment, i enfocant cap al nord ( és l'únic punt cardinal que té camí des del mon virtual ). Per obrir-la s'haurà d'arrastrar la clau al pany de la porta ( detectar col·lisió ). Un cop s'obri la porta, has guanyat la partida.

       



