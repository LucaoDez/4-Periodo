public class Endereco {
    private String rua;
    private int numero;
    private String cidade;
    private String estado;
    private String cep;

    // 🔸 Construtor
    public Endereco(String rua, int numero, String cidade, String estado, String cep) {
        this.rua = rua;
        this.numero = numero;
        this.cidade = cidade;
        this.estado = estado;
        this.cep = cep;
    }

    // 🔸 Getters
    public String getRua(){ return rua; }
    public int getNumero(){ return numero; }
    public String getCidade(){ return cidade; }
    public String getEstado(){ return estado; }
    public String getCep(){ return cep; }

    // 🔸 Setters
    public void setRua(String rua) {
        if(rua != null && !rua.isEmpty()){
            this.rua = rua;
        }
    }

    public void setNumero(int numero) {
        if(numero > 0){
            this.numero = numero;
        }
    }

    public void setCidade(String cidade) {
        if(cidade != null && !cidade.isEmpty()){
            this.cidade = cidade;
        }
    }

    public void setEstado(String estado) {
        if(estado != null && !estado.isEmpty()){
            this.estado = estado;
        }
    }

    public void setCep(String cep) {
        if(cep != null && !cep.isEmpty()){
            this.cep = cep;
        }
    }

    // 🔸 Método extra: exibir endereço formatado
    public String exibirEndereco() {
        return rua + ", " + numero + " - " + cidade + "/" + estado + " - CEP: " + cep;
    }
}
