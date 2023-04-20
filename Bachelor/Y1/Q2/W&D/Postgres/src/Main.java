import java.sql.*;
import java.util.Scanner;

public class Main {
    private static final Scanner terminalScanner = new Scanner(System.in);

    public static void main(String[] args) throws SQLException {
        JDBCUtil jdbcUtil = new JDBCUtil("postgres", "1234", "imdb");
        jdbcUtil.query();

    }
//    public static void main(String[] args) {
//        String url = "jdbc:postgresql://localhost:5432/imdb";
//        String user = "postgres";
//        String pass = "1234";
//        try{
//            Connection connection = DriverManager.getConnection(url,user,pass);
//            System.out.println("What query would you like to execute? ");
//            int queryNumber = 0;
//            if(terminalScanner.hasNext()){
//                queryNumber = Integer.parseInt(terminalScanner.next());
//            }
//
//            switch (queryNumber){
//                case 1:
//                    firstQuery(connection);
//                    break;
//                case 2:
//                    secondQuery(connection);
//                    break;
//                case 3:
//                    thirdQuery(connection);
//                    break;
//                case 4:
//                    break;
//            }
//
//        }catch (SQLException e){
//            System.out.println(e.getMessage());
//        }
//    }

    /**
     * Return all primary titles of a specified genre.
     * @param connection - the database connection
     */
    private static void thirdQuery(Connection connection) throws SQLException {
        System.out.println("Enter the genre : ");
        String genre = "";
        if(terminalScanner.hasNext()){
            genre = terminalScanner.next();
        }
        String sql = "SELECT ti.primary_title FROM titles ti JOIN titles_genres tg ON (ti.title_id = tg.title_id) WHERE tg.genre = ? ;";

        PreparedStatement pstmt = connection.prepareStatement(sql);

        pstmt.setString(1,genre);

        ResultSet rs = pstmt.executeQuery();
        while(rs.next())
            System.out.println(rs.getString(1));
        rs.close();
        pstmt.close();
    }

    /**
     * Return all character names played in titles that contain a specific string in their
     * primary title.
     * @param connection - the database connection
     */
    private static void secondQuery(Connection connection) throws SQLException {
        System.out.println("Enter the string : ");
        String format = "";
        if(terminalScanner.hasNext()){
            format = terminalScanner.next();
        }
        String sql = "SELECT tpc.character_name, ti.primary_title FROM titles ti JOIN title_person_character tpc ON (ti.title_id = tpc.title_id) WHERE ti.primary_title LIKE ? ";

        PreparedStatement pstmt = connection.prepareStatement(sql);

        pstmt.setString(1, "%" + format + "%");

        ResultSet rs = pstmt.executeQuery();
        while(rs.next())
            System.out.println(rs.getString(1));
        rs.close();
        pstmt.close();
    }


    /**
     * Return all primary titles for a specific start year
     * @param connection - the database connection
     * @throws SQLException - if the query does not work
     */
    private static void firstQuery(Connection connection) throws SQLException {
        System.out.println("Enter the start year : ");
        int year = 0;
        if(terminalScanner.hasNext()){
            year = Integer.parseInt(terminalScanner.next());
        }
        String sql = "SELECT primary_title FROM titles ti WHERE ti.start_year = ? ORDER BY ti.primary_title LIMIT 100;";
        PreparedStatement pstmt = connection.prepareStatement(sql);
        pstmt.setInt(1, year);

        ResultSet rs = pstmt.executeQuery();
        while(rs.next())
            System.out.println(rs.getString(1));
        rs.close();
        pstmt.close();
    }
}
