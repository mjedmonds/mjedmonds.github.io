$(document).ready(function() {
  createDeck();
  startOver();
});

    function makeDraggableElement(o){
    o.draggable({
      helper: "clone",
      cursor: "move",
      snap: "true",
      snapTolerance: 50,
      snapMode: "outer",
        distance: 20
    });
  }
  function makeSortableElement(o){
    o.sortable({
        revert: false
    });
  }
  function makeDroppableElement(o){
    o.droppable({
      accept: ".imacard",
      drop: function(event, ui) {
      
      var obj;
        return createNewCard(this, ui.draggable, ui); // this = a .dropzone (#cardContainer1, #cardContainer2, #cardContainer3)
      }
    })
  }

  function createDeck() { //Randomize cards, place into "deck" and build on page
    var deck = shuffleArray(getCards()); //create a new array from the original that we can affect
    for (i = 0; i < deck.length; i++) {
      var newCard = document.createElement("div"); //newly created card
            $(newCard).addClass('hideme imacard');
      $("#motivators").append(newCard); //add the card to the UL      
      $(newCard).html('<div class="cardHeader"><p>' +  deck[i] + '</p></div><img src="assets/inlogo.png" width="87" height="75" alt="LinkedIn Logo"></img>'); //assign text from array based on randomizing done above, add LI logo
    }

    showNextMotivator();
    makeDraggableElement($(".imacard"));
    makeSortableElement($('.dropzone'));
    makeDroppableElement($('.dropzone'));
  }
  
  
  function createNewCard(placement, $item, ui) { //once a card has been dropped, show a new card to be picked up
    if($($item).parents('.dropzone').attr('id') == $(placement).attr('id')){ //sorting happening
            return false; 
    } else { //moving between columns
        $($item).removeClass('draggable').addClass('editable').removeAttr('style');
    }
    var droppedCard = $($item).clone();
        $item.remove(); //delete from the motivators div
        $(placement).append(droppedCard); //add to the dropped column's div
    showNextMotivator(); //make next card visible
    updateCard($(droppedCard));
    return true;
  }

  //Update the card when it's in a column, removing the LI logo and adding comment functionality
  function updateCard(card) {
    var commentBox = document.createElement("textarea");
    var commentBtn = document.createElement("button");
    var commentDelBtn = document.createElement("button");

    card.find('img').remove();

    card.addClass("showme placed");

    card.append(commentBox); //add textarea for comment
    $(commentBox).addClass("commentBox-empty"); //start with the comment box being invisible

    card.append(commentBtn); //add button to show textarea
    $(commentBtn).addClass("commentBtn").attr("id", "commentBtn").text("...");

    card.append(commentDelBtn); //add button to delete comment
    $(commentDelBtn).addClass("commentDelBtn-hide").text("X"); //start with delete button hidden

    $(commentBtn).click(function() {
      card.children('textarea').addClass("commentBox-full").removeClass("commentBox-empty").attr("placeholder", "Add comment..."); //show the comment text area
      $(this).addClass("commentBtn-moved").removeClass("commentBtn"); //move the button over to make room for the delete button
      $(commentDelBtn).removeClass("commentDelBtn-hide").addClass("commentDelBtn"); //show the delete button
    })

    $(commentDelBtn).click(function() {
      card.children('textarea').val('').addClass("commentBox-empty").removeClass("commentBox-full"); //clear out the comment box, hide it
      $(this).addClass("commentDelBtn-hide").removeClass("commentDelBtn"); //hide the delete button
      card.find("#commentBtn").removeClass("commentBtn-moved").addClass("commentBtn"); //move the add comment button back over
    })
  }

  //A way to start over that is more elegant than reloading the page
  function startOver() {
    var restartButton = document.createElement("button");

    $("#startOver").append(restartButton);

    $(restartButton).addClass("restartButton").text("Start Over");
    $(restartButton).click(function() {
      $("#cardContainer1, #cardContainer2, #cardContainer3, #motivators").empty();
      dropCount = 0;
      createDeck();
    })
  }
  
  function showNextMotivator(){ //whichever card is on top of the deck shall be shown
    $("#motivators .imacard.hideme:first-child").addClass('showme').removeClass('hideme'); 
  }


function shuffleArray(a){
    for (let i = a.length; i; i--) {
        let j = Math.floor(Math.random() * i);
        [a[i - 1], a[j]] = [a[j], a[i - 1]];
    }
    return a;
}

function getCards(){
return [
    "Focus on Impact",
    "Flexibility",
    "Time to Reflect",
    "Autonomy",
    "Direction & Guidance",
    "Deadlines",
    "Work Time",
    "Challenging Work",
    "Structure",
    "Accountability",
    "Responsibility",
    "Process and Procedure",
    "Feedback",
    "Clarity on Priorities",
    "Variety of Work",
    "Influence",
    "Learning & Training",
    "Opportunity to be Creative",
    "Collaborate with Others",
    "Time with Manager",
    "Interaction with Others",
    "Consistency",
    "Recognition",
    "Planning & Organization"
  ];
}