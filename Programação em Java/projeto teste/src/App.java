public class App {
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa(); // agora funciona com o construtor vazio
        Pessoa p2 = new Pessoa();

        Endereco e1 = new Endereco("Rua A", 123, "Cidade B", "Estado C", "12345-678");
        Endereco e2 = new Endereco("Rua X", 456, "Cidade Y", "Estado Z", "98765-432");

        Aluno a1 = new Aluno("123456789");

        p1.setNome("LucaoDez");
        p1.setIdade(19);
        p1.setEndereco(e1);

        p2.setNome("Ronaldo");
        p2.setIdade(40);
        p2.setEndereco(e2);

        a1.setRA("123456789");

        System.out.println("Nome da pessoa é: " + p1.getNome());
        System.out.println("A idade da pessoa é: " + p1.getIdade());
        System.out.println("O endereco da pessoa é: " + p1.getEndereco().exibirEndereco());
        System.out.println("O RA da pessoa "+p2.getNome()+" é: " + a1.getRA());
        System.out.println("O endereco da pessoa "+p2.getNome()+ " é: "+p2.getEndereco().exibirEndereco());
        System.out.println("Dados da pessoa: " + p1.toString());

    }
}
