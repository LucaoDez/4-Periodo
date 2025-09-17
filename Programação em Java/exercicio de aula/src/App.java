public class App {
    public static void main(String[] args) throws Exception {
        Mamifero cachorro = new Mamifero("luna", "lulu da polmerania");
        
        System.out.println("Nome do cachorro: " + cachorro.nome);
        System.out.println("Especie do cachorro: " + cachorro.especie);
    }
}
