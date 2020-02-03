/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.LinkedList;
import java.util.Locale;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author kwadwooteng-amoko
 */
public class PoloniexService {

    private Date utcDate;
    private long unixEpochDate;

    // search json for the data
    public ControllerValues readJson() throws MalformedURLException, IOException {
        TimeSeriesAnalysis ts = new TimeSeriesAnalysis();
        String initial_value = new String();
        String rs = "https://poloniex.com/public?command=returnChartData&currencyPair=USDT_BTC&start=1470111048&end=9999999999&period=86400";
        URL jsonSocket = new URL(rs); // URL to Parse
        URLConnection yc = jsonSocket.openConnection();
        BufferedReader in = new BufferedReader(new InputStreamReader(yc.getInputStream()));
        BigDecimal bd;
        BigDecimal bt = BigDecimal.ONE;

        String inputLine;

        ControllerValues cv = new ControllerValues(bt, bt, bt);

        while ((inputLine = in.readLine()) != null) {

            System.out.println(inputLine);

            // Pattern p = Pattern.compile("((\\D+:\\d+\\s+)+)?(\\D+)?:?(\\d+),");//. represents single character  
            // Matcher m = p.matcher("hello:34345 hello:34345 abcde:244,");  
            //boolean b = m.matches();  
            // System.out.println(b);
            //System.out.println("hello>>>>>"+m.group(1));
            //Pattern p = Pattern.compile("((\\D+:\\d+\\s+)+)?(\\D+)?:?(\\d+),");//. represents single character  
            //Matcher m = p.matcher("hello:34345 hello:34345 abcde:244,");  
            //Pattern p = Pattern.compile("\\[?\\{?((\"\\D+\":([0-9]+),)+?)((\"close\":)?)(\\d+.(\\d+))?),?"); 
            //Pattern p = Pattern.compile("\\[?\\{?(((\"\\D+\":([0-9]+.?[0-9]+?)(,)?)+)?((\"close\":)(\\d+.(\\d+))(,)?)?)+?(\\})?(\\])?"); 
            Pattern p = Pattern.compile("(\"close\":\\d+.\\d+)");

            //Matcher m = p.matcher("[{\"date\":1570111048.213,\"high\":8214.26248971,\"low\":8214.26248971,\"open\":8214.77248971,\"close\":99214.996248971,\"date\":1570111048.213,\"high\":8214.26248971,\"low\":8214.26248971,\"open\":8214.77248971,\"close\":8214.996248971}]");  
            Matcher m = p.matcher(inputLine);
            boolean b = m.matches();
            System.out.println(b);
            int groupCount = m.groupCount();
            System.out.println(">>>>>" + m.groupCount());

            LinkedList<BigDecimal> data = new LinkedList<BigDecimal>();

            while (m.find()) {

                for (int i = 0; i < groupCount; i++) {
                    {
                        // remove string elements
                        String ss = m.group(0);
                        String val = ss.replaceAll("[A-Za-z\":]", "");
                        double dd = Double.valueOf(val);
                        bd = BigDecimal.valueOf(dd);
                        if (i == 0) 
                        {
                            initial_value = bd.toString();
                        }
                        
                        System.out.println(bd.toString());
                        ts.setValue(bd);

                    }
                }
            }

            System.out.println(ts.getMean());

        }
        return cv;
    }

    // set the transaction date
    public void setDate(String Date, double clock) throws ParseException {
        DateFormat format = new SimpleDateFormat("dd-M-yyyy hh:mm:ss", Locale.ENGLISH);
        this.utcDate = format.parse("10-2-2019 00:00:00");
    }

    ;
    
    
    // return the current time as an epoch
    public long getDate() throws ParseException {

        long epoch = utcDate.getTime();
        return epoch;
    }

    ;
    
    
     // return the time as an epoch 
     public long getDateNowMinusDays(Integer days) throws ParseException {
        Date today = Calendar.getInstance().getTime();

        long epoch = today.getTime() - (days * 86400000);
        return epoch;
    }

    ;
     
    // return current time as an epoch
    public long getDateNow() throws ParseException {
        Date today = Calendar.getInstance().getTime();

        // return the epoch time
        long epoch = today.getTime();
        return epoch;
    }
;
}
