# CGraphicsSamples

Instrucciones de Instalación:

<ol>
  
<li>Baja los archivos de esta página.</li>
 
 <li>Copia graphics.h y winbgim.h (Ubicados en la carpeta instrucciones) a la carpeta <b>include</b> y <b>MinGW32/include</b> </li>
 
 <li>Copia <b>libbgi.a</b> a la carpeta <b>lib</b> y <b>MinGW32/lib</b></li>
 
 <li>Abre Dev-C++, crea proyecto de consola y pega cualquier código que use graphics.h en tu main.</li>
 
 <li>Project > Project Options > Parameters > *Copiar en Linker, lo que esté dentro de Linker.txt de la carpeta instrucciones* > Aceptar</li>
 
 <li>Repetir paso 5 (sin copiar)</li>
</ol>
¿Díficil? <a href="https://youtu.be/BdRlwJ5As24">Aquí el video</a>

<h4>Preguntas/Errores Frecuentes</h4>
<ul>
  
<li>
  Al momento de compilar dice <i>** missing ...</i> <br>
  R: Ve a Project Options y da clic en OK
  </li>
  

 <li>
  No reconoce la libreria graphics.h <br>
  R: No agregaste la libreria graphics.h a la carpeta include NI a la carpeta MinGW/Include
  
</li>
  
  

</ul>
<h4><a 
href="https://www.cs.colorado.edu/~main/bgi/doc/">
Documentación Oficial de <i>graphics.h</i></a></h4>
<h4><a 
href="https://svwh.dl.sourceforge.net/project/orwelldevcpp/Portable%20Releases/Dev-Cpp%205.3.0.3%20MinGW%204.7.0%20Portable.7z">Descarga de Dev-C++ 5.3.0</a></h4>
