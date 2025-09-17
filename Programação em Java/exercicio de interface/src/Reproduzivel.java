public interface Reproduzivel {
    void reproduzir();
    void parar();
    String getFormato();
    int getDuracao(); //em segundos (para imagem pode ser 0);
}
