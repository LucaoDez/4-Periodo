public class Professor extends Pessoa{
    private double salario;


    public Professor(double salario, String nome, int idade, Endereco endereco){
        super(nome, idade, endereco);
        this.salario = salario;
    }

    public double getSalario(){
        return salario;
    }

}
