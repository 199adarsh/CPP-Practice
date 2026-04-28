import java.util.regex.Matcher;
import java.util.regex.Pattern;

class EmailValidator {

    public static boolean isValidEmail(String email) {
        String regex = "[\\w.-]+@[\\w.-]+\\.[a-z]{2,}$";
        Pattern pat = Pattern.compile(regex);
        Matcher mat = pat.matcher(email); 
        return mat.matches();
    }

    public static void main(String[] args) {
        System.out.println(isValidEmail("test@example.com"));
    }
}