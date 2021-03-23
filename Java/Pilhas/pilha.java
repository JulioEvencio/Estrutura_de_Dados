public class Pilha {
    private final int[] elemento;
    private int tamanho;

    public Pilha(int tamanho) {
        this.elemento = new int[tamanho];
        this.tamanho = 0;
    }

    public boolean isVazia() {
        return this.tamanho == 0;
    }

    public boolean isCheia() {
        return this.tamanho == this.elemento.length;
    }

    public int getTamanho() {
        return this.tamanho;
    }

    public int getElemento() {
        return this.elemento[this.tamanho - 1];
    }

    public void empilhar(int elemento) {
        this.elemento[this.tamanho] = elemento;
        this.tamanho++;
    }

    public int desempilhar() {
        this.tamanho--;
        return this.elemento[this.tamanho];
    }

    public void formatar() {
        this.tamanho = 0;
    }
}