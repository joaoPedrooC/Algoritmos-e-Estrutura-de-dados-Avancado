public class Arvore {
  public No raiz = null;

  public void InserirNo(int valor) {
    No copia_raiz = this.raiz;
    No ponto_insercao = this.raiz;
    No novo_no = new No();

    novo_no.valor = valor;
    novo_no.no_dir = null;
    novo_no.no_esq = null;

    if (this.raiz == null) {
      this.raiz = novo_no;
      return;
    }

    while (copia_raiz != null) {
      ponto_insercao = copia_raiz;

      if (valor < copia_raiz.valor) {
        copia_raiz = copia_raiz.no_esq;
      } else {
        copia_raiz = copia_raiz.no_dir;
      }
    }

    if (valor < ponto_insercao.valor) {
      ponto_insercao.no_esq = novo_no;
    } else {
      ponto_insercao.no_dir = novo_no;
    }
  }

  public boolean Buscar(int valor) {
    boolean encontrado = false;

    No copia_raiz = this.raiz;

    while (copia_raiz != null && !encontrado) {
      if (copia_raiz.valor == valor) {
        encontrado = true;
      } else if (valor < copia_raiz.valor) {
        copia_raiz = copia_raiz.no_esq;
      } else {
        copia_raiz = copia_raiz.no_dir;
      }
    }

    return encontrado;
  }

  public void ImprimirCrescente(No raiz) {
    if (raiz != null) {
      this.ImprimirCrescente(raiz.no_esq);
      System.out.println(raiz.valor + " ");
      this.ImprimirCrescente(raiz.no_dir);
    }
  }

  public void ImprimirDecrescente(No raiz) {
    this.ImprimirDecrescente(raiz.no_dir);
    System.out.println(raiz.valor + " ");
    this.ImprimirDecrescente(raiz.no_esq);
  }

  public int ContarElementos(No raiz) {
    if (raiz != null) {
      return this.ContarElementos(raiz.no_esq) + this.ContarElementos(raiz.no_dir) + 1;
    }

    return 0;
  }

  public int SomarElementos(No raiz) {
    if (raiz != null) {
      return this.SomarElementos(raiz.no_esq) + this.SomarElementos(raiz.no_dir) + raiz.valor;
    }

    return 0;
  }

  public int ProcurarMaiorElemento(No raiz) {
    if (raiz == null) {
      return 0;
    }

    int maior = raiz.valor;

    int resultado_direito = this.ProcurarMaiorElemento(raiz.no_dir);
    int resultado_esquerdo = this.ProcurarMaiorElemento(raiz.no_esq);
    
    if (resultado_direito > maior) {
      maior = resultado_direito;
    }

    if (resultado_esquerdo > maior) {
      maior = resultado_esquerdo;
    }

    return maior;
  
  }
  public int ProcurarMenorElemento(No raiz) {
    if (raiz == null) {
      return -1;
    }

    int menor = raiz.valor;

    int resultado_direito = this.ProcurarMenorElemento(raiz.no_dir);
    int resultado_esquerdo = this.ProcurarMenorElemento(raiz.no_esq);
    
    if (resultado_direito < menor && resultado_direito != -1) {
      menor = resultado_direito;
    }

    if (resultado_esquerdo < menor && resultado_esquerdo != -1) {
      menor = resultado_esquerdo;
    }

    return menor;
  }

  public void ImprimirFolhas(No raiz) {
    if (raiz == null) {
      return;
    }

    if (raiz.no_dir == null && raiz.no_esq == null) {
      System.out.println(raiz.valor + " ");
    }

    this.ImprimirFolhas(raiz.no_esq);
    this.ImprimirFolhas(raiz.no_dir);
  }

  public void ImprimirNaoFolhas(No raiz) {
    if (raiz == null) {
      return;
    }

    if (raiz.no_dir != null || raiz.no_esq != null) {
      System.out.println(raiz.valor + " ");
    }

    this.ImprimirFolhas(raiz.no_esq);
    this.ImprimirFolhas(raiz.no_dir);
  }

  public void RemoverNo(int valor) {
    No percorre_arvore = this.raiz;
    No proximo_vertice = null;
    No temp = null;
    No seguinte = null;

    No anterior = null;

    boolean encontrado = false;

    while (!encontrado && percorre_arvore != null) {
      if (percorre_arvore.valor == valor) {
        encontrado = true;
      } else {
        anterior = percorre_arvore;

        if (valor < percorre_arvore.valor) {
          percorre_arvore = percorre_arvore.no_esq;
        } else {
          percorre_arvore = percorre_arvore.no_dir;
        }
      }
    }

    if (encontrado) {
      
      if (percorre_arvore.no_esq == null) {
        proximo_vertice = percorre_arvore.no_dir;
      } else if (percorre_arvore.no_dir == null) {
        proximo_vertice = percorre_arvore.no_esq;
      } else {
        temp = percorre_arvore;
        proximo_vertice = percorre_arvore.no_dir;
        seguinte = proximo_vertice.no_esq;

        while (seguinte != null) {
          temp = proximo_vertice;
          proximo_vertice = seguinte;
          seguinte = proximo_vertice.no_esq;
        }

        if (temp != percorre_arvore) {
          temp.no_esq = proximo_vertice.no_dir;
          proximo_vertice.no_dir = percorre_arvore.no_dir;
        }

        proximo_vertice.no_esq = percorre_arvore.no_esq;
      }

      if (anterior == null) {
        this.raiz = proximo_vertice;
      } else if (percorre_arvore == anterior.no_esq) {
        anterior.no_esq = proximo_vertice;
      } else {
        anterior.no_dir = proximo_vertice;
      }

    }
  }
}
