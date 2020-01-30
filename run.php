#!/usr/bin/php
<?php

    
 //Link to download file...
    // $url = "https://celestrak.com/satcat/tle.php?CATNR=43108";
    $url = $argv[1];


 //Code to get the file...
 $data = file_get_contents($url);

 //save by filename
    $filename = "/Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/source/resource.html";

 //save the file
 $fh = fopen($filename,"w");
 fwrite($fh,$data);
 fclose($fh);
        
    
?>
