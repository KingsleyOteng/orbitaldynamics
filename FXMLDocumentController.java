/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication3;

//import java.awt.Color;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import java.math.BigDecimal;
import java.math.MathContext;
import java.net.URLConnection;
import java.text.ParseException;
import java.time.Duration;
import java.util.LinkedList;
import java.util.Observable;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javafx.animation.KeyFrame;
import javafx.beans.InvalidationListener;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.shape.Circle;
import javafx.scene.paint.Color;

/**
 * additional information
 * @author kwadwooteng-amoko
 */
public class FXMLDocumentController implements Initializable {

    private final MathContext displayRoundingContext = new MathContext(4);
    private final int roundingPrecision = 2;
    // ClockTimer ktimer;
    Label timeLabel;

    @FXML
    private TextField Trade_Amount;
    
    @FXML
    private TextField stop_loss_parameter;

    @FXML
    private Label label;

    @FXML
    private Label returnYtdLabel1;

    @FXML
    private Label returnYtdLabel2;

    @FXML
    private Label returnYtdLabel3;

    @FXML
    private Circle trade_status_indicator = new Circle();

    @FXML
    private Circle indicator_learning = new Circle();

    @FXML
    private Circle indicator_active = new Circle();

    @FXML
    private Circle circle_a;

    @FXML //vol label
    private Label returnYtdLabel31;

    @FXML
    private Label returnYtdLabel11;

    @FXML
    private Label returnYtdLabel111;

    @FXML
    private Label returnYtdLabel1111;

    @FXML
    private Label returnYtdLabel11111;

    @FXML
    private Label returnYtdLabel11112;

    @FXML
    private Label timer_label;

    @FXML
    private ToggleButton btc_button, xrp_button, eth_button, ltc_button;

    @FXML
    private ToggleGroup currency_select = new ToggleGroup();

    @FXML
    private Button go_button = new Button();

    @FXML
    private void handleButtonAction(ActionEvent event) {
        //System.out.println("You clicked me!");
        label.setText("Hello World!");
        returnYtdLabel2.setText("11%");

        indicator_learning.setFill(javafx.scene.paint.Color.CRIMSON);
        indicator_active.setFill(javafx.scene.paint.Color.CRIMSON);
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        PoloniexService ps = new PoloniexService();
        ControllerValues cv = new ControllerValues();

        
        //starting stop loss set at 15 percent
        stop_loss_parameter.setText("15");
        
        // starting price of 5000 usd
        Trade_Amount.setText("5000");
         
        try {
            cv = ps.readJson();
        } catch (Exception e) {
        };
        // create a toggleGroup for the currencies
        ltc_button.setToggleGroup(currency_select);
        ltc_button.setUserData("LTC");
        btc_button.setToggleGroup(currency_select);
        btc_button.setUserData("BTC");
        eth_button.setToggleGroup(currency_select);
        eth_button.setUserData("ETH");
        xrp_button.setToggleGroup(currency_select);
        xrp_button.setUserData("XRP");

        BigDecimal meanvalue;
        

        try {
            

            TimeSeriesAnalysis set;
            set = FXMLDocumentController.readList(0);

            // set the strategy entry point
            set.setStrike(BigDecimal.valueOf(1000));
            btc_button.setSelected(true);
           
             
            long temp;
            temp = System.currentTimeMillis() / 1000L;
            System.out.println("hello>>>>>>>>>"+String.valueOf(temp));

            // populate window
           
            returnYtdLabel11.setText(set.getStrike().toString());
            returnYtdLabel111.setText(set.getMean().setScale(roundingPrecision, BigDecimal.ROUND_UP).toString());
            returnYtdLabel1111.setText("BTC");
            returnYtdLabel11111.setText("0%");

            //returnYtdLabel11112.setText("0:00:00");
            // generate the return metric
            
           
            BigDecimal nd;
            nd = set.getMean().setScale(roundingPrecision, BigDecimal.ROUND_UP);
            returnYtdLabel1.setText(String.valueOf(set.getMean().setScale(roundingPrecision, BigDecimal.ROUND_UP).subtract(set.getStrike())) );
            returnYtdLabel2.setText((set.getStd().setScale(roundingPrecision, BigDecimal.ROUND_UP)).toString());
            returnYtdLabel3.setText(set.getCount().toString());
            returnYtdLabel31.setText(set.getSqrt(set.getStd()).setScale(roundingPrecision, BigDecimal.ROUND_UP).toString());
        
            
          

        } catch (IOException e) {
        }

        //learning_status_indicator.
        //Circle learning_status_indicator 
        indicator_learning.setFill(javafx.scene.paint.Color.SEASHELL);
        indicator_active.setFill(javafx.scene.paint.Color.SEASHELL);

    }

    // update the traded amount
    public void trade_amount_increase() {
        String current_value;
        Integer integer_Value;

        current_value = Trade_Amount.getText();

        if (current_value.isEmpty()) {
            integer_Value = 0;
        } else {
            integer_Value = Integer.valueOf(current_value);
        }

        integer_Value = integer_Value + 10;

        Trade_Amount.setText(integer_Value.toString());

    }

    ;
    
    // update the traded amount
    public void trade_amount_decreasee() {
        String current_value;
        Integer integer_Value;

        current_value = Trade_Amount.getText();

        if (current_value.isEmpty()) {
            integer_Value = 0;
        } else {
            integer_Value = Integer.valueOf(current_value);
        }

        integer_Value = integer_Value - 10;

        if (integer_Value < 0) {
            integer_Value = 0;
        }

        Trade_Amount.setText(integer_Value.toString());

    }

    ;
    


    // search json for the data
    public static TimeSeriesAnalysis readList(int days_back) throws IOException {
        TimeSeriesAnalysis ts = new TimeSeriesAnalysis();
        String initial_value = new String();
        
        long temp;
        temp = System.currentTimeMillis() / 1000L;
        System.out.println("hello>>>>>>>>>"+String.valueOf(temp));
        //String current_time =  String.valueOf(this.unixtimecurrent());
        
        long back;
        back = (System.currentTimeMillis() / 1000L) - (86400 * 30);;
        System.out.println("hello>>>>>>>>>"+String.valueOf(back));
        
        String rs = "https://poloniex.com/public?command=returnChartData&currencyPair=USDT_BTC&start="+back+"&end="+temp+"&period=86400";
        URL jsonSocket = new URL(rs); // URL to Parse
        URLConnection yc = jsonSocket.openConnection();
        BufferedReader in = new BufferedReader(new InputStreamReader(yc.getInputStream()));

        //String rs2 = "https://poloniex.com/public?command=returnChartData&currencyPair=BTC_ETH&start=1470111048&period=86400";
        try {
            PoloniexService ps = new PoloniexService();
            long timeNow = ps.getDateNow();
            String rs2 = "https://poloniex.com/public?command=returnChartData&currencyPair=BTC_ETH&start=" + timeNow + "&period=86400";
        } catch (ParseException ex) {
            Logger.getLogger(FXMLDocumentController.class.getName()).log(Level.SEVERE, null, ex);
        }
        ;

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
            Pattern p = Pattern.compile("(\"close\":\\d+.?\\d+)");

            //Matcher m = p.matcher("[{\"date\":1570111048.213,\"high\":8214.26248971,\"low\":8214.26248971,\"open\":8214.77248971,\"close\":99214.996248971,\"date\":1570111048.213,\"high\":8214.26248971,\"low\":8214.26248971,\"open\":8214.77248971,\"close\":8214.996248971}]");  
            Matcher m = p.matcher(inputLine);
            
            boolean b = m.matches();
            
                    
                    
            int groupCount = m.groupCount();
        
            
            LinkedList<BigDecimal> data = new LinkedList<BigDecimal>();

            while (m.find()) {

                for (int i = 0; i < groupCount; i++) {
                    
                    // remove string elements
                    String ss = m.group(0);
                    String val = ss.replaceAll("[A-Za-z\":]", "");
                    double dd = Double.valueOf(val);
                    bd = BigDecimal.valueOf(dd);

                    if (i == 0) {
                        initial_value = bd.toString();
                    }

                    ts.setValue(bd);
                }
            }
        }

        return ts;
    }

     // search json for the data
    public static long unixtimecurrent() {
    long ut2 = System.currentTimeMillis() / 1000L;
    return ut2;
    };
    
    public static long unixtimecurrent_backdays(int days_back) {
    long ut2 = System.currentTimeMillis() / 1000L;
    return ut2 - 86400 * days_back;
    };
    
    public static long unixtimecurrent_backhours(int hours_back) {
    long ut2 = System.currentTimeMillis() / 1000L;
    return ut2 - 3600 * hours_back;
    };
    
    public static long unixtimecurrent_backminutes(int minutes_back) {
    long ut2 = System.currentTimeMillis() / 1000L;
    return ut2 - 60 * minutes_back;
    };
}
