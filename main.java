import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpServer;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.nio.charset.StandardCharsets;

public class Main {

    public static void main(String[] args) throws IOException {

        int port = Integer.parseInt(
                System.getenv().getOrDefault("PORT", "8080")
        );

        HttpServer server = HttpServer.create(
                new InetSocketAddress("0.0.0.0", port),
                0
        );

        server.createContext("/", Main::home);
        server.createContext("/hello", Main::hello);

        server.start();

        System.out.println("Server running on port " + port);
    }

    private static void home(HttpExchange exchange) throws IOException {
        sendResponse(exchange,
                "Hello from Java and Google Cloud!");
    }

    private static void hello(HttpExchange exchange) throws IOException {
        sendResponse(exchange,
                "Welcome! My Java application is running on Google Cloud.");
    }

    private static void sendResponse(
            HttpExchange exchange,
            String message) throws IOException {

        byte[] response = message.getBytes(StandardCharsets.UTF_8);

        exchange.getResponseHeaders()
                .set("Content-Type", "text/plain; charset=UTF-8");

        exchange.sendResponseHeaders(200, response.length);

        try (OutputStream output = exchange.getResponseBody()) {
            output.write(response);
        }
    }
}
