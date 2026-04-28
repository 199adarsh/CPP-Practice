import java.text.ParseException;
import java.text.SimpleDateFormat;

class Validator {

    public static boolean isValidDate(String date) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");
        sdf.setLenient(true);

        try {
            sdf.parse(date);
            return true;
        } catch (ParseException e) {
            return false;
        }
    }

    public static void main(String[] args) {
        String date = "21-04-2026";
        System.out.println(isValidDate(date));
    }
}