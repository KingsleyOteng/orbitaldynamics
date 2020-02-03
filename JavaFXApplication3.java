/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication3;

import java.io.IOException;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.math.BigDecimal;
import java.text.ParseException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.geometry.HPos;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.MenuButton;
import javafx.scene.control.MenuItem;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafxapplication3.PoloniexService;

/**
 *
 * @author kwadwooteng-amoko
 */
public class JavaFXApplication3 extends Application {
    
    final String apiKey = "YOUR_API_KEY";
    final String apiSecret = "YOUR_API_SECRET";
    
    String res = "";
    BigDecimal sum = BigDecimal.ZERO;
    
    @Override
    public void start(Stage stage) throws Exception {
        
        Parent root = FXMLLoader.load(getClass().getResource("FXMLDocument.fxml"));
        
        GridPane panex = new GridPane();
        
        panex.setAlignment(Pos.CENTER);
        panex.setHgap(5.5);
        panex.setVgap(5.5); 
        GridPane.setHalignment(new DigitalClock(), HPos.LEFT);
        Label xy = new DigitalClock();
        Label xz = new Label();
        xz.setText("   Details current trade:   4 days,                                         "+"     // BTC //"+" USD$4000");
        panex.add(xz, 0, 1); 
        panex.add(xy, 0, 1); 
        panex.add(root, 0, 2);  
          
        
        StackPane rootPane = new StackPane();
        //Scene scene = new Scene(root);
        Scene scene = new Scene(rootPane);
        Pane pane1 = new Pane();
        Pane pane2 = new Pane();
        
        //rootPane.getChildren().addAll(root);
        rootPane.getChildren().addAll(panex);
     
        //rootPane.getChildren().addAll(root);
        //rootPane.getChildren().addAll(panex);
          
        //Scene scene = new Scene(rootPane);
        stage.setScene(scene);
        stage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException, ParseException {
        
    
        
        PoloniexService ps = new PoloniexService();
        //ps.readJson();
        ps.setDate("2019-03-01", 0);
        System.out.println("long date "+ps.getDate());
        System.out.println("long date extended "+ps.getDateNowMinusDays(3));
        launch(args);
        
    }
    
}
