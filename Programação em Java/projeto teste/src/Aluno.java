public class Aluno extends Pessoa{
    private String RA;

    public Aluno(){
        
    }

    public Aluno(String RA){
        super();
        this.RA = RA;
    }

    public String getRA() {
        return RA;
    }

    public void setRA(String RA){
        if(RA != null && !RA.isEmpty()){
            this.RA = RA;
        }
    }

}
