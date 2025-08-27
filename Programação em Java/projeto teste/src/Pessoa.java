public class Pessoa {
    protected String nome;
    protected int idade;
    protected Endereco endereco;

    public Pessoa() {
    }

    public Pessoa(String nome, int idade, Endereco endereco){
        this.nome = nome;
        this.idade = idade;
        this.endereco = endereco;
    }

    public String getNome(){
        return nome;
    }

    public int getIdade(){
        return idade;
    } 

    public Endereco getEndereco(){
        return endereco;
    }

    public void setNome(String nome){
        if(nome != null && !nome.isEmpty()){
            this.nome = nome;
        }
    }

    public void setIdade(int idade){
        if(idade > 0){
            this.idade = idade;
        }
    }

    public void setEndereco(Endereco endereco){
        this.endereco = endereco;
    }

    public String toString() {
        return "Pessoa{" +
                "nome='" + nome + '\'' +
                ", idade=" + idade +
                ", endereco=" + (endereco != null ? endereco.exibirEndereco() : "Endereço não definido") +
                '}';
    }
}
