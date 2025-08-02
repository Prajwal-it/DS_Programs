import java.sql.*;
import java.util.Scanner;

public class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            // Load JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("Connection Created Successfully");

            // Connect to database
            Connection conn = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/college", "root", "monalididi");
            Statement stmt = conn.createStatement();

            int choice;

            do {
                System.out.println("\n===== MENU =====");
                System.out.println("1. Create Table");
                System.out.println("2. Insert Record");
                System.out.println("3. Update Record");
                System.out.println("4. Delete Record");
                System.out.println("5. Exit");
                System.out.print("Enter your choice: ");
                choice = sc.nextInt();

                switch (choice) {
                    case 1:
                        stmt.execute("CREATE TABLE IF NOT EXISTS wit2 (rollno INT, name VARCHAR(10))");
                        System.out.println("Table created successfully (if it didn’t exist).");
                        break;

                    case 2:
                        System.out.print("Enter Roll No: ");
                        int roll = sc.nextInt();
                        sc.nextLine(); // consume newline
                        System.out.print("Enter Name: ");
                        String name = sc.nextLine();
                        int inserted = stmt.executeUpdate("INSERT INTO wit2 VALUES (" + roll + ", '" + name + "')");
                        System.out.println("Rows Inserted: " + inserted);
                        break;

                    case 3:
                        System.out.print("Enter Old Roll No to Update: ");
                        int oldRoll = sc.nextInt();
                        System.out.print("Enter New Roll No: ");
                        int newRoll = sc.nextInt();
                        int updated = stmt.executeUpdate("UPDATE wit2 SET rollno = " + newRoll + " WHERE rollno = " + oldRoll);
                        System.out.println("Rows Updated: " + updated);
                        break;

                    case 4:
                        System.out.print("Enter Roll No to Delete: ");
                        int deleteRoll = sc.nextInt();
                        int deleted = stmt.executeUpdate("DELETE FROM wit2 WHERE rollno = " + deleteRoll);
                        System.out.println("Rows Deleted: " + deleted);
                        break;

                    case 5:
                        System.out.println("Exiting...");
                        break;

                    default:
                        System.out.println("Invalid choice. Try again.");
                }

            } while (choice != 5);

            conn.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
        }
    }
}
