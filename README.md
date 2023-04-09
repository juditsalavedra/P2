PAV - P2: detección de actividad vocal (VAD)
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*	Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*	Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
	integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central del grupo):
	-	Acceda la página de la [Práctica 2](https://github.com/albino-pav/P2).
	-	En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
		se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
		nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*	Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
	subir sus modificaciones al repositorio central:
	-	En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
		**Collaborators** y añada a su compañero de prácticas.
	-	Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
		propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
		modificaciones de su directorio local de trabajo al repositorio GitHub.
*	En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
	una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
	guion (**fulano-mengano**).
*	Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
	-	Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
		Asegúrese de usar *Clone with HTTPS*.
	-	Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

		```.sh
		git clone dirección-del-fork-de-la-práctica
		```

	-	Vaya al directorio de la práctica `cd P2`.

	-	Cambie a la rama **fulano-mengano** con la orden:

		```.sh
		git checkout fulano-mengano
		```

*	A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
	local del modo habitual, usando el repositorio remoto en GitHub como repositorio central para el trabajo colaborativo
	de los distintos miembros del grupo de prácticas o como copia de seguridad.
	-	Puede *confirmar* versiones del proyecto en su directorio local con las órdenes siguientes:

		```.sh
		git add .
		git commit -m "Mensaje del commit"
		```

	-	Las versiones confirmadas, y sólo ellas, se almacenan en el repositorio y pueden ser accedidas en cualquier momento.

*	Para interactuar con el contenido remoto en GitHub es necesario que los cambios en el directorio local estén confirmados.

	-	Puede comprobar si el directorio está *limpio* (es decir, si la versión actual está confirmada) usando el comando
		`git status`.

	-	La versión actual del directorio local se sube al repositorio remoto con la orden:

		```.sh
		git push
		```

		*	Si el repositorio remoto contiene cambios no presentes en el directorio local, `git` puede negarse
			a subir el nuevo contenido.

			-	En ese caso, lo primero que deberemos hacer es incorporar los cambios presentes en el repositorio
				GitHub con la orden `git pull`.

			-	Es posible que, al hacer el `git pull` aparezcan *conflictos*; es decir, ficheros que se han modificado
				tanto en el directorio local como en el repositorio GitHub y que `git` no sabe cómo combinar.

			-	Los conflictos aparecen marcados con cadenas del estilo `>>>>`, `<<<<` y `====`. Los ficheros correspondientes
				deben ser editados para decidir qué versión preferimos conservar. Un editor avanzado, del estilo de Microsoft
				Visual Studio Code, puede resultar muy útil para localizar los conflictos y resolverlos.

			-	Tras resolver los conflictos, se ha de confirmar los cambios con `git commit` y ya estaremos en condiciones
				de subir la nueva versión a GitHub con el comando `git push`.


	-	Para bajar al directorio local el contenido del repositorio GitHub hay que ejecutar la orden:

		```.sh
		git pull
		```
	
		*	Si el repositorio local contiene cambios no presentes en el directorio remoto, `git` puede negarse a bajar
			el contenido de este último.

			-	La resolución de los posibles conflictos se realiza como se explica más arriba para
				la subida del contenido local con el comando `git push`.



*	Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
	práctica para su evaluación utilizando el mecanismo *pull request*.
	-	Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
		**fulano-mengano**.
	-	Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los
elementos más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a 
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.
  
  Para la realización de esta práctica, hemos grabado un nuevo fichero .wav, cuyo nombre es pav_2352.wav. Abrimos 
  el fichero en la aplicación ***wavesurfer*** y comprobamos que se trata de una señal mono (1 único canal) y con 
  frecuencia de muestreo de 16 kHz:
  
  &nbsp; &nbsp; <img width="242" alt="image" src="https://user-images.githubusercontent.com/127085765/225718076-a729dafe-165f-49e3-906d-2ccd843fe126.png">


  Primero realizamos el etiquetado manual de los segmentos para indicar cuáles se corresponden a segmentos de voz (V)
  y cuáles a segmentos de silencio (S):
  
  &nbsp; &nbsp; <img width="956" alt="image" src="https://user-images.githubusercontent.com/127085765/225719597-dce0f121-e065-43f2-ac6d-a9f9f265a954.png">
  
  Hay que tener en cuenta que se han considerado como silencios aquellos que tienen una cierta duración (no pausas cortas).
  
  
  Usamos el programa implementado en la práctica 1 ***p1*** para obtener los parámetros estadísticos que necesitamos de la señal grabada.
  Como se muestra en la siguiente captura, guardamos la potencia de la señal en un fichero llamado *pav_2352.pot* y la tasa de cruces por cero 
  en el fichero *pav_2352.zcr*. Tenemos en cuenta que al ejecutar **p1**, la salida está compuesta por 4 columnas. La potencia se encuentra en la 
  segunda columna, mientras que el ZCR se encuentra en la cuarta columna. Los comandos usados son:
  
  &nbsp; &nbsp; <img width="654" alt="image" src="https://user-images.githubusercontent.com/127085765/225710248-08487746-441e-4adc-8b3f-2d6fa233c002.png">
  
  
  Ahora añadimos los paneles necesarios para poder ver el contorno de la potencia de la señal y la tasa de cruces por cero (ZCR). En la siguiente 
  captura de pantalla se muestran los siguientes paneles:
  	1. Señal temporal
	2. Panel *transcription* con etiquetas para determinar los segmentos de voz y los de silencio
	3. Potencia de la señal obtenida por ***wavesurfer*** (usando ventana de Hamming de 320 puntos)
	4. Potencia de la señal obtenida con el programa de la práctica 1 *p1*
	5. Tasa de cruces por cero obtenida con el programa de la práctica 1 *p1*
  
  &nbsp; &nbsp; <img width="946" alt="image" src="https://user-images.githubusercontent.com/127085765/225719436-07b9aace-d8d0-4c10-b18f-ef6d84f5076e.png">




- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

	* Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para
	  estar seguros de que un segmento de señal se corresponde con voz.
	  
	 En la gráfica en la que se representa la potencia de la señal de voz obtenida por ***wavesurfer*** se aprecia que el valor de voz posterior a un 
	 silencio (25-40dB) es de aproximadamente 60-80dB. Por otro lado, si nos fijamos en la gráfica obtenida con el programa de P1, vemos que el valor 
	 posterior a un silencio (entre -45dB y -55dB) es de aproximadamente -5dB o -10dB. Decidimos que el incremento del nivel de potencia adecuado para
	 considerar que hay un cambio de silencio a voz es 15dB, aunque depende de la situación, se puede considerar un incremento inferior respecto del 
	 nivel de silencio como 10 dB, ya que hay situaciones en las que es peor detectar silencio cuando es voz que al contrario.
	  
	 Las gráficas se han analizado más detalladamente con wavesurfer, por lo que los valores se ven con más precisión que en la imagen incluida en el
	 apartado anterior. Por ejemplo, en la siguiente captura podemos ver mejor el nivel del silencio:
	  
   &nbsp; &nbsp; <img width="955" alt="image" src="https://user-images.githubusercontent.com/127085765/229853097-de3b5e5c-5ba2-4fda-a1cd-41bfa9a96cac.png">


   * Duración mínima razonable de los segmentos de voz y silencio.
	
     Utilizando el comando "cat" observamos los siguientes segmentos de voz y silencio:<br>

&nbsp; &nbsp; <img width="400" alt="image" src="https://user-images.githubusercontent.com/125377500/226129493-e00437de-1406-4ed5-85dd-18c49f518cc7.png">
	  
     La duración de los segmentos de voz y silencio se puede calcular haciendo la diferencia entre el instante final y el inicial. 
     En nuestro audio, los segmentos de silencio son bastante largos, por lo que consideraremos razonables silencios de 0.5 segundos,
     duración inferior al mínimo valor obtenido con nuestra grabación (0.672 segundos). Por otro lado, consideraremos que la duración
     mínima razonable de los segmentos de voz es 0.3s, que es un poco inferior al mínimo observado (0.372 segundos).
	  

   * ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?
   
     Sabemos que la tasa de cruces por cero nos da información acerca del sonido. Cuando el sonido es sonoro el ZCR tiene valores muy bajos, mientras que 
     en el caso de sonidos sordos, el ZCR aumenta. Aún así, hay que tener en cuenta que no todos los sonidos sordos tienen una tasa de cruces por cero elevada.
     Se observa que la tasa de cruces por cero no es una medida muy precisa para determinar la presencia de sonido o voz. Las señales con una alta tasa de
     cruces por cero suelen tener una mayor presencia de silencios. Sin embargo, algunos sonidos sordos como la **t** o la **s** sproducen valores altos en 
     la gráfica de ZCR. Escuchando el audio (dice: *Hola, soy Teresa, y mi hermana me ha pedido que grabe un audio para la clase de pav*) y mirando nuestra
     gráfica se comprueba que los picos más significativos se corresponden con la letra "s" (consonante fricativa):
	  	1. Pico en intervalo 2,31s : 2,41s -> se corresponde con la 's' de la palabra '***s****oy*'
		2. Pico en intervalo 2,85s : 2,95s -> se corresponde con la 's' de la palabra '*Tere***s***a*'
		3. Pico en intervalo 3,5s : 3,7s   -> silencio (se oye un ruido de fondo)
		4. Pico en intervalo 6,3s : 6,4s   -> se corresponde con la 's' de la palabra '*cla***s***e*'
     
     Vemos que las consonantes sordas como la '***p***' y la '***t***' no tienen un ZCR elevado.
		

### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal en
  tiempo real tan exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.
  
  Para la implementación del código se han hecho pruebas con distintos valores de ***alpha0*** y ***alpha1*** con el objetivo de maximizar la puntuación `TOTAL`. A partir de lo observado se han determinado los valores por defecto que aparecen al ejecutar el comando cuando no se introduce ningún argumento. Además, también se encuentran en el fichero ***vad.docopt***. Los umbrales usados en relación a la tasa de cruces por cero también se han determinado observando los valores de ZCR para algunas de las señales de la base de datos y nuestra grabación usando el programa de la primera práctica y visualizando los resultados mediante el uso de ***wavesurfer***.
  
  &nbsp; &nbsp; <img width="471" alt="image" src="https://user-images.githubusercontent.com/127085765/230739339-6b5ded68-7ab2-420b-bbb0-8a36af76a988.png">


- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 

  A continuación se muestran las capturas (se ha hecho ampliando los tramos para visualizar bien las etiquetas, ya que en el programa se han etiquetado todas las tramas, excepto las indefinidas, que se han considerado como parte de la siguiente trama: si después de tramas indefinidas hay una trama de silencio, ese conjunto de tramas indefinidas se consideran silencio e igual para el caso de voz).
   
   &nbsp; &nbsp; <img width="957" alt="image" src="https://user-images.githubusercontent.com/127085765/230739369-45169304-008e-48ae-bd2e-dbfad0de08b8.png">
   &nbsp; &nbsp; <img width="955" alt="image" src="https://user-images.githubusercontent.com/127085765/230739403-491ffc3c-e4fd-47af-a00a-36397bdc485e.png">
   &nbsp; &nbsp; <img width="957" alt="image" src="https://user-images.githubusercontent.com/127085765/230739429-7ba3fdd5-d09c-4a66-bdbb-a86cf80d5b62.png">
   &nbsp; &nbsp; <img width="956" alt="image" src="https://user-images.githubusercontent.com/127085765/230739458-66d64c6c-2349-432d-96e9-045395635927.png">
   &nbsp; &nbsp; <img width="957" alt="image" src="https://user-images.githubusercontent.com/127085765/230739473-03c24cb9-1737-4848-a419-bcd52cda6ad2.png">
   &nbsp; &nbsp; <img width="957" alt="image" src="https://user-images.githubusercontent.com/127085765/230739485-eb1ade74-b767-4de9-9ea3-437ea7009dcf.png">
   &nbsp; &nbsp; <img width="464" alt="image" src="https://user-images.githubusercontent.com/127085765/230739509-bfb17ab1-4620-43a0-8f5d-4e9dad6cd0d6.png">
  

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.
  
  Hay que tener en cuenta que el etiquedato manual se ha realizado de forma aproximada en función de la forma de onda de la señal de voz, lo escuchado al reproducir los segmentos de la señal y usando los gráficos de potencia y ZCR (tasa de cruces por cero). Si comparamos el manual con la detección automática, vemos que coinciden mucho. A continuación mostramos el resultado obtenido al evaluar la detección automática comparándola con la realizada manualmente:
  
  &nbsp; &nbsp;<img width="647" alt="image" src="https://user-images.githubusercontent.com/127085765/230739638-db595862-53bd-4d15-8136-dc99c7dd76f8.png">
  
  Como podemos ver, el TOTAL obtenido es muy elevado. Viendo las capturas del apartado anterior, nos fijamos que hay muy pocas tramas identificadas erróneamente. Además observamos que los errores se corresponden con las últimas y las primeras tramas de segmento de voz que se consideran silencio. Estos errores, sin embargo, se pueden producir también al realizar el etiquetado manual, ya que no es evidente el instante en el que termina o empieza exactamente un segmento de voz.


- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).
  
  Evaluamos los resultados sobre la base de datos usando `scripts/run_vad.sh $alpha0 $alpha1`, dónde ***alpha0*** y ***alpha1*** son los argumentos que se deben pasar. Hemos elegido los valores a partir de la realización de muchas pruebas y viendo para cuáles se consigue un resultado mejor. Como se puede observar en el resumen, lo mejor que hemos conseguido ha sido un 91.92%:
 
 &nbsp; &nbsp; <img width="669" alt="image" src="https://user-images.githubusercontent.com/127085765/230739964-e78ce3d6-7131-4353-92a3-35d7e5ee025d.png">

 Queremos destacar que la puntuación-F `TOTAL` conseguida para *Voz* es mejor que para *Silence*, hecho importante a tener en cuenta en función de la situación en la que se usa el detector automático. hay casos en los que es mejor confundir silencio por voz que al revés, como sería en el caso de silenciar a las personas que no están hablando en un *meet*.

### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).
  
  
  ![image](https://user-images.githubusercontent.com/125377500/230802373-5201b4df-551c-4301-a704-c7fc9edf9169.png)

  
  
  
  
  

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.
  
  Hemos usado `docopt_c` para gestionar los valores de ***alpha0*** y ***alpha1***. De este modo, el usuario puede ejecutar el programa probando con distintos valores de ***alpha*** y ver los resultados obtenidos para cada uno de ellos. Puede ser interesante observar que dependiendo de la señal de voz, puede ser mejor usar unos valores de ***alpha*** más elevados (si la potencia de ruido es baja y la voz tiene potencia muy elevada) o más bajos (si se trata de una señal de voz en la que el hablante hablaba bajo o la potencia de error era bastante notable). Estos factores se tienen que tener en cuenta porque afectan a la detección de voz.
  El mensaje de ayuda del programa es:
  
  &nbsp; &nbsp; <img width="567" alt="image" src="https://user-images.githubusercontent.com/127085765/230740142-1c02d604-ac2f-47b7-be9e-160b2dd56564.png">

  Como se muestra a ontinuación sale el mensaje que hemos determinado en el fichero `vad_docopt`:
  &nbsp; &nbsp; <img width="512" alt="image" src="https://user-images.githubusercontent.com/127085765/230740342-3add5a10-3942-4724-b65c-136808b34671.png">


### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).
  
  Como se ha indicado en el enunciado de la práctica, a parte de la potencia, también hya otros parámetros. Hemos decidido usar los valores de la tasa de cruces por cero como condición para determinar si una trama es Voz o Silencio. 
  Además, como se nos ha indicado en el pdf, hemos decidido que las N primeras tramas de la señal se considere como estado ST_INIT y se han usado para calcular el nivel de potencia del silencio k0.

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que
  considere de interés de cara a su evaluación.


### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.
