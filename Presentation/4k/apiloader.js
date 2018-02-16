    $(document).ready(function() {
//30596
//1688
//48988
 //MovieDB
    var top=[];
    top[2]={"overview":"In 1905, revolutionist Sun Yat-Sen visits Hong Kong to discuss plans with Tongmenghui members to overthrow the Qing dynasty. But when they find out that assassins have been sent to kill him, they assemble a group of protectors to prevent any attacks.",
            "poster_path":"/kXvp9rXJt2j85mGJgkh9CoCMxeB.jpg",
            "title":"Bodyguards and Assassins"}
    top[1]={"overview":"In a futuristic world that has embraced ape slavery, Caesar, the son of the late simians Cornelius and Zira, surfaces after almost twenty years of hiding out from the authorities, and prepares for a slave revolt against humanity.",
            "poster_path":"/wxanhJ9ZuZ05P4J2hkC1M1rA0dv.jpg",
            "title":"Conquest of the Planet of the Apes"}
    top[0]={"overview":"When best buds Rick and Fred begin to show signs of restlessness at home, their wives take a bold approach to revitalize their marriages: they grant the guys a hall pass one week of freedom to do whatever they want. At first, it seems like a dream come true, but they quickly discover that their expectations of the single life - and themselves - are completely and hilariously out of sync with reality.",
            "poster_path":"/hRvf9rhmwIzvfZwQx4IT6xsUhPe.jpg",
            "title":"Hall Pass"}
      //#1
      var mdbPoster='<img src=\"https://image.tmdb.org/t/p/w342';

      $( ".title1" ).html( top[2]['title'] );
      if(top[2]['poster_path'])$( ".mdbImg1" ).html( mdbPoster+ top[2]['poster_path'] + '\">' );
      $( ".description1" ).html( top[2]['overview'] );

      $( ".title2" ).html( top[1]['title'] );
      if(top[1]['poster_path'])$( ".mdbImg2" ).html( mdbPoster+ top[1]['poster_path'] + '\">' );
      $( ".description2" ).html( top[1]['overview'] );

      $( ".title3" ).html( top[0]['title'] );
      if(top[0]['poster_path'])$( ".mdbImg3" ).html( mdbPoster+ top[0]['poster_path'] + '\">' );
      $( ".description3" ).html( top[0]['overview'] );

    });//docready
