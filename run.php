<?php

 //Link to download file...
 $url = "https://celestrak.com/satcat/tle.php?CATNR=43108";

 //Code to get the file...
 $data = file_get_contents($url);

 //save by filename
 $filename = "resource.html";

 //save the file
 $fh = fopen($filename,"w");
 fwrite($fh,$data);
 fclose($fh);
    
?>
