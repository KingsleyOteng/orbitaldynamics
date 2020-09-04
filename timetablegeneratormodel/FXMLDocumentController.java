
package timetablegeneratormodel;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.Button;
import java.sql.*;

/**
 * @details text file generator from ODBC; to be used with the space scheduling program
 * @author kwadwooteng-amoko
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML
    private Label label;
    
    @FXML
    private Button update_button;
    
    @FXML
    private Button connect_button;
    
    @FXML
    private Button download_button;
     
    @FXML
    private PasswordField password;
    
    @FXML
    private PasswordField username;
    
    @FXML
    private PasswordField logfile;
    
    @FXML
    private PasswordField database;
    
    @FXML
    private void handleButtonAction(ActionEvent event) {
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
