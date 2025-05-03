## 3D-CNC-Plotter
<p>This a Hardware project demonstrating the built and functionality of a Make-shift 3D CNC Plotter</p>

# Software Requirements
<ol>
  <li>Arduino IDE (Legacy IDE (1.8.X)) <a href="https://www.arduino.cc/en/software/#ide">Link</a></li>
  <li>Universal G-Code Sender</li>
  <li>GRBL <a href="https://github.com/TGit-Tech/GRBL-28byj-48">Link</a></li>
  <li>Inkscape <a href="https://inkscape.org/release/inkscape-1.4/windows/64-bit/msi/">Link</a></li>
  <li>JS-Cut <a href="https://jscut.org/jscut.html">Link</a></li>
</ol><hr>
<p>I have used an Arduino Uno R3 to power the circuit, other than that 12v of external power supply was also given</p>
<p>I've provided the necessary GRBL file.</p>

<!-- Add an image of the Actual Hardware Circuit and Tinkercad Circuit -->
![CNC Plotter Tinker circuit](https://github.com/user-attachments/assets/e438ef4d-7f9c-447b-90b2-b8d53e51ce96)



<ol>Procedure
<li>Install the Arduino IDE</li>
<li>Include the downloaded GRBL ZIP file</li>
<li>After including the GRBL ZIP File, go to File ---> Examples ---> grbl --> grblUpload </li>
<li>Upload the code</li>
<li>Use the Inkscape software to make a SVG File</li>
<li>In your desired webbrowser, search for JSCut</li>
<li>Open your SVG file in JSCut</li>
<li>Explore its features</li>
<li>Generate toolpath</li>
<li>Genrate the GCode</li>
<li>Save the GCode, as a Local file (it will be saved in your Downloads folder)</li>
<li>Extract the UGS Folder</li>
<li>Open the UGS Folder --> bin --> ugsplatform.exe </li>
<li>In the top left corner of the UGS click File --> open --> open your GCode fie</li>
<li>Select the bound and then select its Port</li>
<li>Click the plug-like icon to Connect the firmware</li>
<li>In the down right corner, in a dark backdrop, the text "IDLE" would be displayed if it is connected successfully</li>
<li>In the top panel of this software, there would be a Visualizer, click it to Visualize the process of printing process</li>
<li>Click a point in your Visualizer window, which displays your output --> right click --> Set toolpath, with this your printer will start printing instantly instead of travelling to it and then carrying out that process</li>
</ol>
